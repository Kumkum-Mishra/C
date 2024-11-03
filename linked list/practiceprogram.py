def max_of_numbers(a,b,c):
    if a>b and a>c:
        return a
    elif b>a and b>c:
        return b
    else:
        return c
a=int(input("enter the number a:"))
b=int(input("enter the number b:"))
c=int(input("enter the number c:"))
max=max_of_numbers(a,b,c)
print("the maximum of three numbers is:",max)

# second question
def sum(list1):
    total = 0
    for num in list1:
        total=total+num
    return total
def multiply(list2):
    product=1
    for num in list2:
        product*=num
    return product

list1= [8,2,3,0,7]
list2= [2,2,1,3,2]

total_sum = sum(list1)
ans=multiply(list2)
print("The sum of all the numbers in the list is:", total_sum)
print("the product of the numbers is:",ans)

# forth question
def reverse_string(s):
    return s[::-1]

sample_string = "1234abcd"

reversed_string = reverse_string(sample_string)
print("The reversed string is:", reversed_string)

# fifth question
def factorial(n):
    s=1
    while(n!=1):
        s=s*n
        n=n-1
    return s    
n=int(input("enter the number:"))
fact=factorial(n)
print("factorial of",n,"is",fact)

# sixth question
def count_case(s):
    upper_case = 0
    lower_case = 0
    
    for x in s:
        if x.isupper():
            upper_case += 1
        elif x.islower():
            lower_case += 1
    
    return upper_case, lower_case

sample_string ="My Name Is Kumkum"

upper_case, lower_case = count_case(sample_string)

print("Number of uppercase letters:", upper_case)
print("Number of lowercase letters:", lower_case)

#seventh question

