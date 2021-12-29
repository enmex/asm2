#include <stdlib.h>

char* getSubstr(char* str, int str_length, int substr_pos, int substr_length) {

	char* result;

	__asm {
		//proverka na nol`/null
		mov		eax, str
		cmp		eax, 0
		je		STR_NULL

		mov		eax, substr_pos
		cmp		eax, 0
		jl		INVALID_SUBSTR_POS

		mov		eax, str_length
		cmp		eax, 0
		jle		INVALID_STR_LENGTH

		mov		eax, substr_length
		cmp		eax, 0
		jle		INVALID_SUBSTR_LENGTH

		//proverka chto pozicia stroki ne vyhodit za stroku
		mov		eax, substr_pos
		inc		eax
		cmp		eax, str_length
		jg		SUBSTR_POS_BEYOND_STR
		jmp		CALL_MALLOC

	CALL_MALLOC:
		//vydelyaem pamyat`
		mov		eax, substr_length
		inc		eax 
		push	eax
		call	malloc

		add		esp, 4

		//podgotovka k cycle
		mov		esi, str
		mov		ecx, substr_pos
		xor		ebx, ebx

	GET_SUBSTR_CYCLE:
		cmp		ebx, substr_length
		jge		ADD_NULL_CHAR
		mov		dl, [esi][ecx]
		mov		[eax][ebx], dl

		inc		ebx
		inc		ecx
		jmp		GET_SUBSTR_CYCLE


	ADD_NULL_CHAR:
		mov		[eax][ebx], '\0'
		jmp		END

	SUBSTR_POS_BEYOND_STR :
		xor		eax, eax
		jmp		END

	STR_NULL:
		xor		eax, eax
		jmp		END

	INVALID_SUBSTR_POS:
		mov		eax, str
		jmp		END

	INVALID_STR_LENGTH:
		mov		eax, str
		jmp		END

	INVALID_SUBSTR_LENGTH:
		mov		eax, str
		jmp		END

	END:
		mov		result, eax

	}
	return result;
}