![img](etc/violet.png) Violet VM
=========

> Toy virtual machine with 3 registers and 3 commands . it has no practical use, just plain fun .

### Build :
    $ cmake CMakeLists.txt && make
    
### Usage :
Run a program :

    $ violet /path/to/bin.s
    
Compile program from source :

    $ vlasm /path/to/source.vl /path/to/bin.s


### Assembly syntax :

Instruction               | Description
--------------------------|---------------------------------------------------------
`loadi [reg][val]`        | load __immediate__ value(__[val]__) to register(__[reg]__) 
`add [reg1][reg2][reg3]`  | place the sum of __[reg2]__ and __[reg3]__ into __[reg1]__  
`halt`                    | stop the execution 

3 General purpose registers available `r0`,`r1` and `r2` .

### Example program

    ; comments start with semicolon
    loadi r0 100
    loadi r1 200
    add r2 r0 r1
    ; now r2 holds the value 300
    halt
    
Same program compiled to vm bytecode :  
    
      6410 c811 0122 0000  