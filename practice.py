import pandas as pd 

student_data = {'Name': ['Aayush','Ben','Charan','Dhruv'],
				'RollNo.': [10,20,30,40],
				'Age': [18,18,19,18]}

df = pd.DataFrame(student_data)

df['Gender'] = ['M','F','M','F']
print(df,'\n')

#print the names of students
print(df.Name,'\n') #df[Name] also works