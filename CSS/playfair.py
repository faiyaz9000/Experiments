alpha='ABCDEFGHIKLMNOPQRSTUVWXYZ'
key = input("Enter the key: ")
msg = input("Enter the msg: ")
#converts to uppercase
key = key.upper()
msg = msg.upper()
unrep=[]
key=list(key)
for i in alpha:
	if i not in key:
		unrep.append(i)		#alters alpha
key = list(dict.fromkeys(key))		
#dict.fromkeys(key)-> this creates a dictionary using the its key as the parameter passed, 
#since dictionary doesnt have duplicate key.. all duplicate things r removed
final=key+unrep
matrix = []
k=0
for i in range(0,5):
	matrix.append([])
for i in range(0,5):
	for j in range(0,5):
		matrix[i].append(j)
		matrix[i][j]=final[k]
		k=k+1
msg=list(msg)
#removing spaces from msg
for i in range(len(msg)):
		if " " in msg:
			msg.remove(" ")
#If both letters are the same, add an "X" after the first letter.
i=0
x=int(len(msg)/2)
for e in range(0,x):
	if msg[i]==msg[i+1]:
		msg.insert(i+1,'X')
	i=i+2
#If it is odd digit, add an "X" at the end
if len(msg)%2==1:
	msg.append("X")
#finds position
def find_position(matrix,letter):
	x=y=0
	for i in range(0,5):
		for j in range(0,5):
			if matrix[i][j]==letter:
				x=i
				y=j
	return x,y
cipher=[]
x=len(msg)-1
i=0
while i<x:
	p1,q1=find_position(matrix,msg[i])
	i=i+1
	p2,q2=find_position(matrix,msg[i])
	if p1==p2:
		if q1==4:
			q1=-1
		if q2==4:
			q2=-1
		cipher.append(matrix[p1][q1+1])
		cipher.append(matrix[p1][q2+1])		
	elif q1==q2:
		if p1==4:
			p1=-1;
		if p2==4:
			p2=-1;
		cipher.append(matrix[p1+1][q1])
		cipher.append(matrix[p2+1][q2])
	else:
		cipher.append(matrix[p1][q2])
		cipher.append(matrix[p2][q1])
	i=i+1
print("Cipher text: ",end='')
for i in cipher:
	print(i,end='')
print()
