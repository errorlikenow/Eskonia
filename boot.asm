BITS 16  start:    

    mov eax, cr0    
    or eax, 1    
    mov cr0, eax      ; Загрузка GDT
    lgdt []     
    jmp 0x08:protected_mode 
    protected_mode:     ; Установка сегмента данных    
        mov ax, 0x10     
        mov ds, ax     
        mov es, ax    
        mov fs, ax     
        mov gs, ax      ; Установка стека     
        mov esp, stack_top      ; Инициализация видеорежима    
        mov ah, 0x00     
        mov al, 0x13    
        int 0x10      ; Отрисовка приветственного экрана     
        mov si, welcome_message    
        call print_string      ; Загрузка программы loginuser    
        call load_program      ; Бесконечный цикл     
        jmp $  print_string:    ; Вывод строки    
        mov ah, 0x0E 
        print_next_char:     
        lodsb    
        cmp al, 0     
        je print_done
        int 0x10    
        jmp print_next_char 
        print_done:        
        ret
        load_program:    
        ; Загрузка программы loginuser    
        mov ah, 0x03
        mov al, 0x00
        mov bx, 0x0000   
        mov cx, 0x0000    
        mov dx, 0x7E00    
        int 0x13    
        ; Переход к программе loginuser    
        jmp 0x7E00:0x0000  
        welcome_message db "Welcome to MyOS!", 0 
        stack_top dd 0x0000FFFF
        gdt_descriptor dw
        gdt_end - gdt_start - 1
        gdt_start: 
        
        ; NULL descriptor     
        dd 0x00000000
        dd 0x00000000 
        
        ; Code segment descriptor     
        dw 0xFFFF   
        dw 0x0000    
        db 0x00   
        db 0x9A  
        db 0xCF  
        db 0x00      ; Data segment descriptor
        dw 0xFFFF   
        dw 0x0000  
        db 0x00  
        db 0x92    
        db 0xCF  
        db 0x00 
        gdt_end: 
        times 510-($-$$) 
        db 0
        dw 0xAA55