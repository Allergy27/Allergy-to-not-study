def is_prime(number):
    if number < 2:
        return False
    for i in range(2, int(number**0.5) + 1):
        if number % i == 0:
            return False
    return True
n=int(input())
for i in range(1,n+1):
    k=0
    j=1
    while k<i**2:
        if not is_prime(j+((i+k-1)%26)+65):
            print(end=" ")
            j+=1
        else:
            print(chr(((i+k-1)%26)+65),end="")
            k+=1
            j+=1
    print()