midfix = input()

stack = []
postfix = ''

for item in midfix:
    backpos = len(stack)-1

    if item=='+' or item=='-':
        while (backpos != -1) and (stack[backpos] != '(' and stack[backpos] != ')'):
            postfix += stack.pop()
            backpos = len(stack) - 1
        stack.append(item)
    elif item=='*' or item=='/':
        while (backpos != -1) and (stack[backpos] == '*' or stack[backpos] == '/'):
            postfix += stack.pop()
            backpos = len(stack) - 1
        stack.append(item)
    elif item == '(':
        stack.append(item)
    elif item == ')':
        while (stack[backpos] != '('):
            postfix += stack.pop()
            backpos = len(stack) - 1
        stack.pop()
    else:
        postfix += item

while(len(stack) != 0):
    postfix += stack.pop()


print(postfix)
