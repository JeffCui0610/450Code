

import sys
input_file=str(sys.argv[1])

f = open(input_file, "r")
# f = open("input.txt", "r")
txt_list=[]
txt=f.readline()
txt_list.append(txt)
while txt:
    txt = f.readline()
    txt_list.append(txt)
txt_list.pop(-1)

nums="0123456789"
letter="QWERTYUIOPLKJHGFDSAZXCVBNM"

priority_list=list(filter(lambda i:i!=' ', list(txt_list[-1])))

counter=0
source_order_dic={}
for i in priority_list:
    if i not in source_order_dic:
        source_order_dic[i]=counter
        counter+=1

# my code could deal with unknown number of sources and the time stamp could be
# # more than 10 or even more than a hundred
# time_data_dic= dict(v,k) for k,v in source_order_dic.items())

data_time_dic={}
for i in txt_list:
    temp_num=""
    start_end=[]
    counter=7
    while counter<len(i) and i[counter]!="\n":
        if i[counter] in nums:
            temp_num+=i[counter]
        else:
            if temp_num:
                start_end.append(int(temp_num))
                temp_num=""
        if len(start_end)==2:
            data_time_dic[i[counter+1:counter+3]]=start_end
            start_end=[]
            counter+=3
        else:
            counter+=1

time_data_dic= dict((tuple(v),k) for k,v in data_time_dic.items())

#calculate speed
total_data=0
min_time=float('inf')
max_time=float('-inf')
for i in data_time_dic:
    left=data_time_dic[i][0]
    right=data_time_dic[i][1]
    total_data+=right-left
    if left<min_time:
        min_time=left
    if right>max_time:
        max_time=right
speed=total_data/(max_time-min_time)
#print(speed)
while True:
    if 1000000%speed==0:
        break
    else:
        speed=int(speed+1)

slot_unit=1/speed

time_counter=min_time



temp_list=[(i, data_time_dic[i], source_order_dic[i[0]]) for i in data_time_dic]

temp_list.sort(key=lambda i:[i[1][0],i[2]])


output=[((ord(temp_list[i][0][0])-ord("A")),
         int(temp_list[i][1][0]/speed) if temp_list[i][1][0]%speed==0 else temp_list[i][1][0]/speed,
         int(temp_list[i][1][1]/speed) if temp_list[i][1][1]%speed==0 else temp_list[i][1][1]/speed,
         temp_list[i][0]) for i in range(1)]
# print(output)
for i in range(1, len(temp_list)):
    base=output[-1][2]
    # left= int(temp_list[i][1][0]/speed) if temp_list[i][1][0]%speed==0 else temp_list[i][1][0]/speed
    left=base
    right=(temp_list[i][1][1]-temp_list[i][1][0])/speed
    right+=base
    right=int(right) if right-int(right)==0 else right
    output.append(((ord(temp_list[i][0][0])-ord("A")),left,right,temp_list[i][0]))




# output.insert(0, "SF")
# output.append("EF")
with open('lab4_result.txt', 'w') as the_file:
    the_file.write("SF\n")
    for i in output:
        the_file.write(str(i[0]))
        the_file.write(", ")
        the_file.write(str(i[1]))
        the_file.write(" ")
        the_file.write(str(i[2]))
        the_file.write(" ")
        the_file.write(str(i[3]))
        the_file.write("\n")
    the_file.write("EF")

print("SF")
for i in output:
    print(str(i[0]),",",str(i[1]),str(i[2]),str(i[3]))
print("EF")


