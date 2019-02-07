# -*- coding: utf-8 -*-
"""
Created on Tue Feb  5 10:19:15 2019

@author: dinhthanhhai
"""

import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

#Importing the dataset
data = pd.read_csv("googleplaystore.csv")

print(data.shape)

#lets look at the column Name in our data
print(data.columns)

#Check value Null
print(data.isnull().sum())

#Lets look at the Rating column
print(data.Rating.head(10))

#Drop the row containing the App Category 1.9 as
# seems to be irrelavant
print(data.index[data['Rating'] == 19].tolist())

data.drop(data.index[10472], inplace=True)
data.reset_index()

print(data.shape)

print(data.isnull().sum())
# We have two categories Free : 10039 and Paid: 800
print(data.Type.value_counts())
#
data.Type.fillna('Free', inplace=True)
#print(data.Type.isnull().sum())

#this column shows the app version I assume, so it is
# better to fill the missing value with
# 'Varies with Device" which is also the max occuring amongst apps
print(data['Current Ver'].value_counts())
data['Current Ver'].fillna('Current Ver', inplace=True)
print(data['Current Ver'].isnull().sum())

#check "Android ver"
print(data['Android Ver'].value_counts())

data['Android Ver'].fillna('4.1 and up', inplace=True)
print(data.isnull().sum())

# Xoá + và , trong cột Installs
data['Installs'] = data['Installs'].apply(lambda x : x.replace('+','') if '+' in str(x) else x)
data['Installs'] = data['Installs'].apply(lambda x : x.replace(',','') if ',' in str(x) else x)
data['Installs'] = data['Installs'].apply(lambda x : int(x))

temp = data.size

print(temp)

data.Size = data.Size.str.replace('.','')

data.Size = data.Size.replace('1000+',1000)
data.Size = data.Size.str.replace('k','000')
data.Size = data.Size.str.replace('M','000000')


print(data.Size.value_counts())

print(data.isnull().sum())


labels = data.Category.value_counts(sort = True).index
cnt = data.Category.value_counts(sort = True)

plt.pie(cnt,labels=labels,shadow=True,autopct='%1.2f%%')
plt.show()


sns.countplot(x='Rating', data=data)
plt.xticks(rotation='vertical')


sns.countplot(x='Genres', data=data)
plt.xticks(rotation='vertical')
# active au-dessus si vous voudriez avoir un bon image
plt.figure(figsize = (5, 5))

#sns.countplot(x='Content Rating', data=data, hue='Installs')
#plt.xticks(rotation='vertical')

labels = data.Type.value_counts(sort = True).index

cnt = data.Type.value_counts(sort = True)
plt.pie(cnt, labels = labels, autopct='%1.1f%%')
plt.show()
