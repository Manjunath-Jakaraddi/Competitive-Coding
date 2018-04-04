with open("res", "w") as r:
    with open("totaldump", "r") as f:
        data = f.read()
        data = data.split('\n')
        hexline = 0
        for line in data:
            num = str(hex(hexline))[2:]
            pad = (7-len(num)) * '0'
            text =  pad + num + " " + ' '.join(line.split(' ')[1:]) + '\n'
            r.write(text)
            hexline += 16
