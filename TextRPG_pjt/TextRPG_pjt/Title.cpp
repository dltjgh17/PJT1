#include "Title.h"
#include <conio.h>
#include <string>

/*단일 인스턴 생성*/
std::unique_ptr<Title> Title::instance = nullptr;
Title* Title::getInstance() 
{
	static Title instance;  
	return &instance;
}

/* 게임 시작 화면*/
std::string Title::GameStart()
{
	while (true)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << " _______   ______   **      **_   ________     " << std::endl;
		std::cout << "|__   **| |  **__| \\\\ \\  //   /  |__   __|  " << std::endl;
		std::cout << "   | |    | |__     \\\\ \\//   /      | |     " << std::endl;
		std::cout << "   | |    |  __|     \\\\     /       | |      " << std::endl;
		std::cout << "   | |    | |____    // /\\\\ \\       | |     " << std::endl;
		std::cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << std::endl;
		std::cout << std::endl;
		std::cout << "            R          P         G             " << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "          >>> 아무 키나 누르세요. <<<            " << std::endl;
		std::cout << std::endl;

		if (false == LoginCheck)
		{
			_getch();
			LoginCheck = true;
		}

		std::cout << "      이름을 입력하세요 (최소 1글자 3글자 이하)    " << std::endl;
		std::cout << "          이름 : ";

		/*이름 생성*/
		std::getline(std::cin, Name);

		// 공백 제거 후 검증
		std::string trimmedName = Name;
		// 앞뒤 공백 제거
		trimmedName.erase(0, trimmedName.find_first_not_of(" \t"));
		trimmedName.erase(trimmedName.find_last_not_of(" \t") + 1);

		// 입력 검증
		if (trimmedName.empty())
		{
			std::cout << "❌ 오류: 이름을 입력해주세요!" << std::endl;
			std::cout << "아무 키나 눌러 다시 입력하세요...";
			_getch();
			continue;
		}

		if (trimmedName.length() < 1 || trimmedName.length() > 3)
		{
			std::cout << "❌ 오류: 이름은 1글자 이상 3글자 이하로 입력해주세요!" << std::endl;
			std::cout << "아무 키나 눌러 다시 입력하세요...";
			_getch();
			continue;
		}

		// 영어만 입력했는지 확인
		bool isEnglishOnly = true;
		for (char c : trimmedName)
		{
			if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
			{
				isEnglishOnly = false;
				break;
			}
		}

		if (!isEnglishOnly)
		{
			std::cout << "❌ 오류: 영어만 입력해주세요!" << std::endl;
			std::cout << "아무 키나 눌러 다시 입력하세요...";
			_getch();
			continue;
		}

		// 모든 검증 통과
		Name = trimmedName;
		break;
	}
	return Name;
}

/*게임 종료 화면*/
void Title::GameEnd()
{
	system("cls");
	std::cout << std::endl;
	std::cout << " _______   ______   __      ___   ________     " <<	std::endl;
	std::cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " <<	std::endl;
	std::cout << "   | |    | |__     \\\\ \\//   /      | |     " <<	std::endl;
	std::cout << "   | |    | |____    // /\\\\ \\       | |     " <<	std::endl;
	std::cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " <<	std::endl;
	std::cout << std::endl;													
	std::cout << "            R          P         G             " <<	std::endl;
	std::cout << std::endl;													
	std::cout << std::endl;													
	std::cout << "             >>> 다음에 만나요!!!! <<<           " <<	std::endl;
	std::cout << "             >>> 다음에 만나요!!!! <<<           " <<	std::endl;
	std::cout << "             >>> 다음에 만나요!!!! <<<           " <<	std::endl;
	std::cout << std::endl;													
	std::cout << "   | |    |  __|     \\\\     /       | |      " <<	std::endl;
	std::cout << std::endl;


}

/* 게임 오버 화면*/
void Title::GameOver()
{
	system("cls");
	std::cout << std::endl;
	std::cout << " _______   ______   __      ___   ________     " << std::endl;
	std::cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << std::endl;
	std::cout << "   | |    | |__     \\\\ \\//   /      | |     " << std::endl;
	std::cout << "   | |    |  __|     \\\\     /       | |      " << std::endl;
	std::cout << "   | |    | |____    // /\\\\ \\       | |     " << std::endl;
	std::cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << std::endl;
	std::cout << std::endl;											
	std::cout << "            R          P         G             " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;;							    
	std::cout << "       >>>          유 다이ㅋ     <<<           " << std::endl;
	std::cout << "       >>>          유 다이ㅋ     <<<           " << std::endl;
	std::cout << "       >>>          유 다이ㅋ     <<<           " << std::endl;
	std::cout << "       >>>          유 다이ㅋ     <<<           " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

/* 전투 승리 화면*/
void Title::Victory()
{
	system("cls");
	std::cout << std::endl;
	std::cout << " _______   ______   __      ___   ________     " << std::endl;
	std::cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << std::endl;
	std::cout << "   | |    | |__     \\\\ \\//   /      | |     " << std::endl;
	std::cout << "   | |    |  __|     \\\\     /       | |      " << std::endl;
	std::cout << "   | |    | |____    // /\\\\ \\       | |     " << std::endl;
	std::cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << std::endl;
	std::cout << std::endl;
	std::cout << "            R          P         G             " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;;
	std::cout << " >>>      WIN! WINER! CHICKEN! DINER!    <<<   " << std::endl;
	std::cout << " >>>      WIN! WINER! CHICKEN! DINER!    <<<   " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

/* 게임 승리 화면*/
void Title::EndVictory()
{
	system("cls");
	std::cout << "                                   ~,                      " << std::endl;
	std::cout << "                                 .=.  $!                   " << std::endl;
	std::cout << "                                 #-   -@                   " << std::endl;
	std::cout << "                                *;-    $                   " << std::endl;
	std::cout << "           *.                   #!,  .,;,                  " << std::endl;
	std::cout << "        @   .;                  #!~   ,;.                  " << std::endl;
	std::cout << "        @    .!                 @.   . :,                  " << std::endl;
	std::cout << "       @      :                 #$*   -=.                  " << std::endl;
	std::cout << "       1      .!                @*,. ,*#                   " << std::endl;
	std::cout << "       1       !               ;*@#:-!;$                   " << std::endl;
	std::cout << "       1       ~!               ###$;:;;!                  " << std::endl;
	std::cout << "       1   :   -;              #:--. ~:!                   " << std::endl;
	std::cout << "       1   @*-$.=             .**!~   :~                   " << std::endl;
	std::cout << "        !!!;@!$$,!            $,,..  ,*~                   " << std::endl;
	std::cout << "        !!!$#!~  =            #$=!.   !;                   " << std::endl;
	std::cout << "         !;~!=.  ~#          ,*;*!-   ;!                   " << std::endl;
	std::cout << "         !;;*..   ;,         -.*---,  :!                   " << std::endl;
	std::cout << "         !;-.#;   =#         **@$$!  .*!                   " << std::endl;
	std::cout << "          ;~=. ,   ~,        $;@@#!##.:*                   " << std::endl;
	std::cout << "           @ *$.   .#        $ !=.. . :!                   " << std::endl;
	std::cout << "           = #. *~!-@,       $,..,   !!:                   " << std::endl;
	std::cout << "           !;!@#:~@!=#       #*-. , -~$.                   " << std::endl;
	std::cout << "           -=*@@#*-!,$       $=#-    .#                    " << std::endl;
	std::cout << "            #:!$=. , ~-      #:=*,. .-$                    " << std::endl;
	std::cout << "            !!=.::    #      @;,    .;!                    " << std::endl;
	std::cout << "             @;!!,    =~    .$*$:,   !!                    " << std::endl;
	std::cout << "             ;!$-~    -$    ,@==~    ;;                    " << std::endl;
	std::cout << "              @-~*,  ~,=~   -$;:!;..~=;                    " << std::endl;
	std::cout << "              ;=;~;-  ,.#   ~$#$=!.  =;                    " << std::endl;
	std::cout << "              .@!~~=$-::**-,@#@@=@#*!=;                    " << std::endl;
	std::cout << "               =:-#;*!*;..;#@##***$$*@@$**-                " << std::endl;
	std::cout << "               -$-!*!$.-  !@@;-,. ,@@#.    =~.             " << std::endl;
	std::cout << "               -#:#@..  --=#@@#;;~#@#        $,            " << std::endl;
	std::cout << "               .@~@#@=-   ;$@@@@#; =-        ;$            " << std::endl;
	std::cout << "               .@,.;.$$==!-.       ,$     , -##,           " << std::endl;
	std::cout << "               ,@~~@        .~     !=~    ,,,@#*;*$#-      " << std::endl;
	std::cout << "               -#*@$~,= .    $, .$,.=-    ,~#@#     ,#     " << std::endl;
	std::cout << "               ~$$!@.:-: .     . ..=;   . ~-@:       ,@    " << std::endl;
	std::cout << "               #!#!@=~.. .       !#:  .. ,#@-      ,. :*   " << std::endl;
	std::cout << "               @#!$##;-,,,.-- **==*....,-@$        .,  @-  " << std::endl;
	std::cout << "              ,@#,~:!=#$!!*=@#$$$=:.,,.-=!     . ,  ~- -#  " << std::endl;
	std::cout << "              @@~-:;==*;~=@@@##!*!*=:-~@:       . .-~~  @  " << std::endl;
	std::cout << "             ~@!,;.:-~*;*=@@@:~.!,~!*~@$!,.  ..,-,:*~.  @. " << std::endl;
	std::cout << "             !# ~-;,,.. ~*@@#:;.-.:,:=$.:*--   ,=$@=-;!,@- " << std::endl;
	std::cout << "            .@,,.-~,    ,!@@;,,-,.,-*=.-:;*:!,~@@##**~-.@  " << std::endl;
	std::cout << "            !! ,.. -. .!~$@$-; .~;.;#-...:!:-~@@$@@@@@@-@  " << std::endl;
	std::cout << "            @-   -     ,*!# ..=-..~@- ,-.,::,@*#@$$#@$@=@  " << std::endl;
	std::cout << "           !@.-  .    .;!!; .  $ .@;#=--,.!~@@@~=*#$-   @  " << std::endl;
	std::cout << "           *=.-  .,--.-~*=.. ;.~.#~.. .$..*@ -@$@: ,##$,@  " << std::endl;
	std::cout << "           !@!--.....* !@!:..# .#!   --;.=@;,  =;-$!=#=#=  " << std::endl;
	std::cout << "           ;@;; -.. , :*#@#!..$@@:- ,-;;##.     ,:.*~-!@   " << std::endl;
	std::cout << "            @:=*,,,.-..*@@@@@@@@@$-=;;$@$~-      ,-.*:;#   " << std::endl;
	std::cout << "            *=..~,,,.:!#!!**.,-=@@@#@@@@,;.     ..!-~=:*   " << std::endl;
	std::cout << "            ,@-..,#~;:!,# #    .-!::=@@=#.,.     -. :;#,   " << std::endl;
	std::cout << "             *$;.;~!*; =,~*        -*$*=;=  -,..~~::-,#    " << std::endl;
	std::cout << "             ,@:~--~-.:, ;.        ,-$;=-=,, ~-~,:~;;!@    " << std::endl;
	std::cout << "              :@~-*~ ~, ,-         , =;!,.$  .--,~~.:~$    " << std::endl;
	std::cout << "               ==;~;,,.        .   , *;~! ;.. ..:,!- #!    " << std::endl;
	std::cout << "               .@$ -:.!           .  !.,*-,= ,~~,.:-,@     " << std::endl;
	std::cout << "                ,@-.*!,,-         -  :. * ,-.,;:.:..!*     " << std::endl;
	std::cout << "                 .@,. -~ ..    .. . ~...!..,--~~.$.~#      " << std::endl;
	std::cout << "                  .@# .-..*-.       ~  .-.   ~:!.- @!      " << std::endl;
	std::cout << "                   .@.,! *,; .          ...   ;.~ ;=       " << std::endl;
	std::cout << "                    .@*# ~:,, ~.-,  .   ~ , . =, !@        " << std::endl;
	std::cout << "                     .$;.;--..  . , --. :.:;= -:.#.        " << std::endl;
	std::cout << "                      $$ --~;,..-,~:-~-~-;:,..! =:         " << std::endl;
	std::cout << "                      =:,,-~=-~:,!:.~;,~,  !    @          " << std::endl;
	std::cout << "                      =-,-;;*,;;! -!,:-~..! ! .~@          " << std::endl;
	std::cout << "                      $- .,:;-::-- ,-:; ..:*--. @          " << std::endl;
	std::cout << "                      #-..;::-:.-..     -:-;    #          " << std::endl;
	std::cout << "                      #.  ~-;,.!=      ,,.,.    #          " << std::endl;
	std::cout << "                      #  ,.-=$;~*----, - -,-   .@          " << std::endl;
	std::cout << "                      @   ,:~~*!!  .,,,, ~     -#          " << std::endl;
	std::cout << "                      =    ~,.;,~~-:~-     !,  ,#          " << std::endl;
	std::cout << "                     ~-    .,,-=       ,,      .#          " << std::endl;
	std::cout << "                     $-    -.;                  -          " << std::endl;
	std::cout << "                     =                                     " << std::endl;
	std::cout << "                                                           " << std::endl;
}
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    

