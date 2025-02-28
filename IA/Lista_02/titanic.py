import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
import plotly.express as px
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from yellowbrick.classifier import ConfusionMatrix
from sklearn import tree
import pickle

# Carregar os dados
data = pd.read_csv('titanic.csv')

# Visualizar as primeiras linhas
data.head()

# Remover colunas irrelevantes ou com muitos valores ausentes
data.drop(columns=['Cabin', 'Ticket', 'Name', 'PassengerId'], inplace=True)

# Preenchendo valores ausentes
data['Age'].fillna(data['Age'].median(), inplace=True)
data['Embarked'].fillna(data['Embarked'].mode()[0], inplace=True)

# Transformação de dados categóricos
cols_label_encode = ['Sex', 'Embarked']
data[cols_label_encode] = data[cols_label_encode].apply(LabelEncoder().fit_transform)

# Separar variáveis independentes e dependentes
X_prev = data.drop(columns=['Survived'])
y_classe = data['Survived']

# Dividir os dados em treino e teste
X_treino, X_teste, y_treino, y_teste = train_test_split(X_prev, y_classe, test_size=0.20, random_state=42)

# Salvar os dados pré-processados
with open('titanic.pkl', 'wb') as f:
    pickle.dump([X_treino, X_teste, y_treino, y_teste], f)

# Definição de hiperparâmetros para Decision Tree
params = {
    'criterion':  ['gini', 'entropy'],
    'max_depth':  [None, 2, 4, 6, 8, 10],
    'max_features': [None, 'sqrt', 'log2', 0.2, 0.4, 0.6, 0.8],
}

modelo = GridSearchCV(
    estimator=DecisionTreeClassifier(),
    param_grid=params,
    cv=10,
    n_jobs=5,
    verbose=1,
)

modelo.fit(X_treino, y_treino)
print("Melhores hiperparâmetros:", modelo.best_params_)
print("Melhor pontuação:", modelo.best_score_)

# Treinar modelo final com os melhores hiperparâmetros
modelo_final = DecisionTreeClassifier(
    max_depth=modelo.best_params_['max_depth'],
    criterion=modelo.best_params_['criterion'],
    max_features=modelo.best_params_['max_features']
)
modelo_final.fit(X_treino, y_treino)

# Fazer previsões
previsoes = modelo_final.predict(X_teste)

# Avaliação do modelo
print("Acurácia:", accuracy_score(y_teste, previsoes))
print("Relatório de classificação:\n", classification_report(y_teste, previsoes))

# Matriz de confusão
cm = ConfusionMatrix(modelo_final)
cm.fit(X_treino, y_treino)
cm.score(X_teste, y_teste)

# Visualização da árvore de decisão
previsores = X_prev.columns.tolist()
figura, eixos = plt.subplots(nrows=1, ncols=1, figsize=(10, 10))
tree.plot_tree(modelo_final, feature_names=previsores, class_names=['Não sobreviveu', 'Sobreviveu'], filled=True);
plt.show()
