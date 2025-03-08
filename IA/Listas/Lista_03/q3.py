import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split, GridSearchCV, RandomizedSearchCV
from sklearn.tree import DecisionTreeClassifier
from skopt import BayesSearchCV

# Carregar os dados
data = pd.read_csv("titanic.csv")

# Remover colunas irrelevantes
data.drop(columns=['Cabin', 'Ticket', 'Name', 'PassengerId'], inplace=True)

# Preenchendo valores ausentes
data['Age'].fillna(data['Age'].median(), inplace=True)
data['Embarked'].fillna(data['Embarked'].mode()[0], inplace=True)

# Transformação de dados categóricos
cols_label_encode = ['Sex', 'Embarked']
data[cols_label_encode] = data[cols_label_encode].apply(LabelEncoder().fit_transform)

# Separar variáveis independentes e dependentes
X = data.drop(columns=['Survived'])
y = data['Survived']

# Dividir os dados em treino e teste
X_treino, X_teste, y_treino, y_teste = train_test_split(X, y, test_size=0.20, random_state=42)

# Definir hiperparâmetros
params = {
    'criterion': ['gini', 'entropy'],
    'max_depth': [None, 2, 4, 6, 8, 10],
    'min_samples_split': [2, 5, 10],
    'min_samples_leaf': [1, 2, 4],
    'max_features': [None, 'sqrt', 'log2']
}

# GridSearchCV
grid_search = GridSearchCV(
    DecisionTreeClassifier(), 
    param_grid=params, 
    cv=5, 
    n_jobs=-1, 
    verbose=1
)
grid_search.fit(X_treino, y_treino)

print("Melhores parâmetros (GridSearchCV):", grid_search.best_params_)
print("Acurácia (GridSearchCV):", grid_search.best_score_)

# RandomizedSearchCV
random_search = RandomizedSearchCV(
    DecisionTreeClassifier(), 
    param_distributions=params, 
    n_iter=10, 
    cv=5, 
    n_jobs=-1, 
    verbose=1, 
    random_state=42
)
random_search.fit(X_treino, y_treino)

print("Melhores parâmetros (RandomizedSearchCV):", random_search.best_params_)
print("Acurácia (RandomizedSearchCV):", random_search.best_score_)

# BayesSearchCV
bayes_search = BayesSearchCV(
    DecisionTreeClassifier(), 
    search_spaces=params, 
    cv=5, 
    n_iter=10, 
    n_jobs=-1, 
    verbose=1, 
    random_state=42
)
bayes_search.fit(X_treino, y_treino)

print("Melhores parâmetros (BayesSearchCV):", bayes_search.best_params_)
print("Acurácia (BayesSearchCV):", bayes_search.best_score_)
