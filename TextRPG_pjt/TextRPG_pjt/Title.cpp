#include "Title.h"
#include <conio.h>

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
	std::cout << " _______   ______   __      ___   ________     " << std::endl;
	std::cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << std::endl;
	std::cout << "   | |    | |__     \\\\ \\//   /      | |     " << std::endl;
	std::cout << "   | |    |  __|     \\\\     /       | |      " << std::endl;
	std::cout << "   | |    | |____    // /\\\\ \\       | |     " << std::endl;
	std::cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << std::endl;
	std::cout << std::endl;
	std::cout << "            R          P         G             " << std::endl;
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "          >>> 아무 키나 누르세요. <<<            " << std::endl;
	std::cout << std::endl;;
		if (false == LoginCheck)
		{
			_getch();
			LoginCheck = true;
		}
		std::cout << "      영어 약자로 이름을 입력하세요 (3글자 이하)    "  << std::endl;
		std::cout << "          이름 : ";
		
		/*이름 생성*/
		std::cin >> Name;

		if (Name.length() < 5)
		{
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore();
			system("cls");
		}

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
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    

