.global _addLargeNumbers
_addLargeNumbers:
pushl   %ebp
movl    %esp, %ebp
//Pre-process first string
movl    8(%ebp), %esi
pushl   %esi
call    _strLen
pushl   %eax
call    _verifyString
cmp     $0 , %eax
je      notNum
call    _shiftRight
addl    $4, %esp
//Pre-process second string
movl    12(%ebp), %esi
pushl    %esi
call     _strLen
pushl    %eax
call     _verifyString
cmp      $0 ,  %eax
je       notNum
call     _shiftRight
addl     $4, %esp
//Popping strings:
//num1 goes %esi, num2 goes %edx
//result goes %edi
popl     %edx
popl     %esi
movl    16(%ebp), %edi
//This part is for after the shift
//%esi = numbers 1, %edx = numbers 2
//%edi = result and %ecx = counter
movl    $254, %ecx
addLoop:
cmp     $0 , %ecx
jl      doneAdding
movb    (%esi,%ecx,1), %al
movb    (%edx,%ecx,1), %ah
addb    %al, %ah
movb    %ah, (%edi,%ecx,1)
dec     %ecx
jmp     addLoop
//Overflow checking.
//Should the number overflow at the
//most signifigant digit, the number
//Will be lost.
doneAdding:
movl    $254, %ecx
doneAddingLoop:
cmp     $0 , %ecx
je      lastCheck
subb    $48, (%edi,%ecx,1)
cmpb     $57, (%edi,%ecx,1)
jg     overflow
dec     %ecx
jmp     doneAddingLoop
overflow:
subb    $10, (%edi,%ecx,1)
dec     %ecx
addb    $1 , (%edi,%ecx,1)
jmp     doneAddingLoop
lastCheck:
subb    $48, (%edi,%ecx,1)
cmp     $57, (%edi,%ecx,1)
jl     lastOverflow
jmp     cleanUp
lastOverflow:
subb    $10, (%edi,%ecx,1)
jmp     cleanUp
//Cleaning up the result:
//This will left shift the array.
cleanUp:
cmpb     $48, (%edi,%ecx,1)
jne      foundStart
inc     %ecx
jmp     cleanUp
foundStart:
xorl    %ebx, %ebx
leftShift:
movb    (%edi,%ecx,1), %al
movb    %al, (%edi,%ebx,1)
inc     %ebx
inc     %ecx
cmp     $255, %ecx
je      allDone
jmp leftShift
allDone:
movl    $0 , (%edi,%ebx,1)
movl 	$1, %eax
leave
ret
//If the string is not a number,
//It will return with 0.
notNum:
xorl    %eax, %eax
leave
ret


//shiftRight
//shifts a string to the right.
//push the string, then the length.
.global _shiftRight
_shiftRight:
pushl   %ebp
movl    %esp, %ebp
movl    8(%ebp), %ebx
movl    12(%ebp), %esi
movl    $255, %ecx
shift:
cmp     $0 , %ebx
jl      fill
movb    (%esi,%ebx,1), %al
movb    %al, (%esi,%ecx,1)
dec     %ecx
dec     %ebx
jmp     shift
fill:
cmp     $0 , %ecx
jl      doneShift
movb    $48, (%esi,%ecx,1)
dec     %ecx
jmp     fill
doneShift:
leave
ret

//This will return the string
//Length, index of null
//push string to be analyzed.
.global _strLen
_strLen:
push	%ebp
movl	%esp, %ebp
movl 	8(%ebp), %edi
movl 	$256, 	%ecx
movl 	$257, 	%eax
movb 	$0 , %al
cld
repne 	scasb
subl 	%ecx, %eax
dec 	%eax
leave
ret

//Verifies that the string
//is a number.
//push string, then counter.
.global _verifyString
_verifyString:
push	%ebp
movl	%esp, %ebp
movl 	8(%ebp), %ecx
movl 	12(%ebp), %edi
xorl 	%eax, %eax
dec 	%ecx
verifyNext:
cmp		$0 , %ecx
jl		done
cmpb	$48, (%edi, %ecx, 1)
jl		notAString
cmpb	$57, (%edi, %ecx, 1)
jg		notAString
dec 	%ecx
jmp		verifyNext
done:
inc 	%eax
notAString:
leave
ret