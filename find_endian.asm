.data
    testObj:.byte '1'
    big:    .asciiz "Big Endian\n"
    little: .asciiz "Little Endian\n"

.text
    main:
        # load "1" as charakter
        li $v0, 4
        la $t0, testObj

        # if testObj != 0
        bne $t0, $zero, bothZero
        li  $v0, 4
        la  $a0, little

        j endExecution
    
    bothZero:
        li $v0, 4
        la $a0, big
        syscall

        j endExecution
    
    endExecution:
        li $v0, 10
        syscall

# works by loading "1" as a charakter in byte = (0000 0001)_2
# big endian systems read it like (0000 0001)
# little endian system read it like (1000 0000)
# to figure out if our system is big or little endian we let the cpu read the byte and then can ask it if the first bit it read was 1 or 0
# if it was 1 it is little endian, if it was 0 then it is big endian