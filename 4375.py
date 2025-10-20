while True:
    try:                n = int(input())
    except EOFError:    break

    r = 0
    length = 0
    while True:
        length += 1
        r = (r * 10 + 1) % n
        if r == 0:
            print(length)
            break