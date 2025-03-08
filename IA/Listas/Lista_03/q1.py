import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# Carregar os dados
data = pd.read_csv('titanic.csv')

# Remover colunas irrelevantes ou com muitos valores ausentes
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
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=42)

# Criar modelos com os critérios Gini e Entropy
model_gini = DecisionTreeClassifier(criterion='gini', max_depth=4, random_state=42)
model_entropy = DecisionTreeClassifier(criterion='entropy', max_depth=4, random_state=42)

# Treinar os modelos
model_gini.fit(X_train, y_train)
model_entropy.fit(X_train, y_train)

# Fazer previsões
y_pred_gini = model_gini.predict(X_test)
y_pred_entropy = model_entropy.predict(X_test)

# Avaliação do modelo com Gini
print("\n### Árvore com Gini ###")
print("Acurácia:", accuracy_score(y_test, y_pred_gini))
print(classification_report(y_test, y_pred_gini))

# Avaliação do modelo com Entropy
print("\n### Árvore com Entropy ###")
print("Acurácia:", accuracy_score(y_test, y_pred_entropy))
print(classification_report(y_test, y_pred_entropy))

# Matriz de Confusão
def plot_confusion_matrix(y_true, y_pred, title):
    cm = confusion_matrix(y_true, y_pred)
    plt.figure(figsize=(5,4))
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=['Não Sobreviveu', 'Sobreviveu'], yticklabels=['Não Sobreviveu', 'Sobreviveu'])
    plt.xlabel('Previsto')
    plt.ylabel('Real')
    plt.title(title)
    plt.show()

plot_confusion_matrix(y_test, y_pred_gini, "Matriz de Confusão - Gini")
plot_confusion_matrix(y_test, y_pred_entropy, "Matriz de Confusão - Entropy")

# Visualização das árvores
def plot_decision_tree(model, title):
    plt.figure(figsize=(12, 8))
    plot_tree(model, feature_names=X.columns, class_names=['Não Sobreviveu', 'Sobreviveu'], filled=True)
    plt.title(title)
    plt.show()

plot_decision_tree(model_gini, "Árvore de Decisão - Critério Gini")
plot_decision_tree(model_entropy, "Árvore de Decisão - Critério Entropy")
