﻿#include "Title.h"

unique_ptr<Title> Title::instance = nullptr;
Title* Title::getInstance() 
{
	static Title instance;  
	return &instance;
}

/* 게임 시작 화면*/
string Title::GameStart()
{
	while (true)
	{
		system("cls");
		cout << endl;
		cout << " _______   ______   __      ___   ________     " << endl;
		cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
		cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
		cout << "   | |    |  __|     \\\\     /       | |      " << endl;
		cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
		cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
		cout << endl;
		cout << "            R          P         G             " << endl;
		cout << endl;;
		cout << endl;;
		cout << "          >>> 아무 키나 누르세요. <<<            " << endl;
		cout << endl;;
		if (false == LoginCheck)
		{
			_getch();
			LoginCheck = true;
		}
		cout << "      영어 약자로 이름을 입력하세요 (3글자 이하)    "  << endl;
		cout << "          이름 : ";
		
		/*이름 생성*/
		cin >> Name;

		if (Name.length() < 5)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}

	}
	return Name;
}

void Title::GameEnd()
{
	system("cls");
	cout << endl;
	cout << " _______   ______   __      ___   ________     " << endl;
	cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
	cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
	cout << "   | |    |  __|     \\\\     /       | |      " << endl;
	cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
	cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
	cout << endl;
	cout << "            R          P         G             " << endl;
	cout << endl;
	cout << endl;
	cout << "             >>> 다음에 만나요!!!! <<<           " << endl;
	cout << "             >>> 다음에 만나요!!!! <<<           " << endl;
	cout << "             >>> 다음에 만나요!!!! <<<           " << endl;
	cout << endl;
	cout << endl;


}

/* 게임 오버 화면*/
void Title::GameOver()
{
	system("cls");
	cout << endl;
	cout << " _______   ______   __      ___   ________     " << endl;
	cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
	cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
	cout << "   | |    |  __|     \\\\     /       | |      " << endl;
	cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
	cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
	cout << endl;
	cout << "            R          P         G             " << endl;
	cout << endl;
	cout << endl;;
	cout << "       >>>          유 다이ㅋ     <<<         " << endl;
	cout << "       >>>          유 다이ㅋ     <<<         " << endl;	
	cout << "       >>>          유 다이ㅋ     <<<         " << endl;	
	cout << "       >>>          유 다이ㅋ     <<<         " << endl;
	cout << endl;
	cout << endl;
}

/* 게임 승리 화면*/
void Title::Victory()
{
	system("cls");
	cout << endl;
	cout << " _______   ______   __      ___   ________     " << endl;
	cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
	cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
	cout << "   | |    |  __|     \\\\     /       | |      " << endl;
	cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
	cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
	cout << endl;
	cout << "            R          P         G             " << endl;
	cout << endl;
	cout << endl;;
	cout << "       >>>      WIN! WINER! CHICKEN! DINER!    <<<         " << endl;
	cout << "       >>>      WIN! WINER! CHICKEN! DINER!    <<<         " << endl;
	cout << endl;
	cout << endl;
}

/* 게임 승리 화면*/
void Title::EndVictory()
{                                                                                                 
 cout <<"                                   ~,                      " << endl;                           
 cout <<"                                 .=.  $!                   " << endl;                           
 cout <<"                                 #-   -@                   " << endl;                           
 cout <<"                                *;-    $                   " << endl;                           
 cout <<"           *.                   #!,  .,;,                  " << endl;                           
 cout <<"        @   .;                  #!~   ,;.                  " << endl;                           
 cout <<"        @    .!                 @.   . :,                  " << endl;                           
 cout <<"       @      :                 #$*   -=.                  " << endl;                           
 cout <<"       1      .!                @*,. ,*#                   " << endl;                           
 cout <<"       1       !               ;*@#:-!;$                   " << endl;                           
 cout <<"       1       ~!               ###$;:;;!                   " << endl;                           
 cout <<"       1   :   -;              #:--. ~:!                   " << endl;                           
 cout <<"       1   @*-$.=             .**!~   :~                   " << endl;                           
 cout <<"        !!!;@!$$,!            $,,..  ,*~                   " << endl;                           
 cout <<"        !!!$#!~  =            #$=!.   !;                   " << endl;                           
 cout <<"         !;~!=.  ~#          ,*;*!-   ;!                   " << endl;                           
 cout <<"         !;;*..   ;,         -.*---,  :!                   " << endl;                           
 cout <<"         !;-.#;   =#         **@$$!  .*!                   " << endl;                           
 cout <<"          ;~=. ,   ~,        $;@@#!##.:*                   " << endl;                           
 cout <<"           @ *$.   .#        $ !=.. . :!                   " << endl;                           
 cout <<"           = #. *~!-@,       $,..,   !!:                   " << endl;                           
 cout <<"           !;!@#:~@!=#       #*-. , -~$.                   " << endl;                           
 cout <<"           -=*@@#*-!,$       $=#-    .#                    " << endl;                           
 cout <<"            #:!$=. , ~-      #:=*,. .-$                    " << endl;                           
 cout <<"            !!=.::    #      @;,    .;!                    " << endl;                           
 cout <<"             @;!!,    =~    .$*$:,   !!                    " << endl;                           
 cout <<"             ;!$-~    -$    ,@==~    ;;                    " << endl;                           
 cout <<"              @-~*,  ~,=~   -$;:!;..~=;                    " << endl;                           
 cout <<"              ;=;~;-  ,.#   ~$#$=!.  =;                    " << endl;                           
 cout <<"              .@!~~=$-::**-,@#@@=@#*!=;                    " << endl;                           
 cout <<"               =:-#;*!*;..;#@##***$$*@@$**-                " << endl;                           
 cout <<"               -$-!*!$.-  !@@;-,. ,@@#.    =~.             " << endl;                           
 cout <<"               -#:#@..  --=#@@#;;~#@#        $,            " << endl;                           
 cout <<"               .@~@#@=-   ;$@@@@#; =-        ;$            " << endl;                           
 cout <<"               .@,.;.$$==!-.       ,$     , -##,           " << endl;                           
 cout <<"               ,@~~@        .~     !=~    ,,,@#*;*$#-      " << endl;                           
 cout <<"               -#*@$~,= .    $, .$,.=-    ,~#@#     ,#     " << endl;                           
 cout <<"               ~$$!@.:-: .     . ..=;   . ~-@:       ,@    " << endl;                           
 cout <<"               #!#!@=~.. .       !#:  .. ,#@-      ,. :*   " << endl;                           
 cout <<"               @#!$##;-,,,.-- **==*....,-@$        .,  @-  " << endl;                           
 cout <<"              ,@#,~:!=#$!!*=@#$$$=:.,,.-=!     . ,  ~- -#  " << endl;                           
 cout <<"              @@~-:;==*;~=@@@##!*!*=:-~@:       . .-~~  @  " << endl;                           
 cout <<"             ~@!,;.:-~*;*=@@@:~.!,~!*~@$!,.  ..,-,:*~.  @. " << endl;                           
 cout <<"             !# ~-;,,.. ~*@@#:;.-.:,:=$.:*--   ,=$@=-;!,@- " << endl;                           
 cout <<"            .@,,.-~,    ,!@@;,,-,.,-*=.-:;*:!,~@@##**~-.@  " << endl;                           
 cout <<"            !! ,.. -. .!~$@$-; .~;.;#-...:!:-~@@$@@@@@@-@  " << endl;                           
 cout <<"            @-   -     ,*!# ..=-..~@- ,-.,::,@*#@$$#@$@=@  " << endl;                           
 cout <<"           !@.-  .    .;!!; .  $ .@;#=--,.!~@@@~=*#$-   @  " << endl;                           
 cout <<"           *=.-  .,--.-~*=.. ;.~.#~.. .$..*@ -@$@: ,##$,@  " << endl;                           
 cout <<"           !@!--.....* !@!:..# .#!   --;.=@;,  =;-$!=#=#=  " << endl;                           
 cout <<"           ;@;; -.. , :*#@#!..$@@:- ,-;;##.     ,:.*~-!@   " << endl;                           
 cout <<"            @:=*,,,.-..*@@@@@@@@@$-=;;$@$~-      ,-.*:;#   " << endl;                           
 cout <<"            *=..~,,,.:!#!!**.,-=@@@#@@@@,;.     ..!-~=:*   " << endl;                           
 cout <<"            ,@-..,#~;:!,# #    .-!::=@@=#.,.     -. :;#,   " << endl;                           
 cout <<"             *$;.;~!*; =,~*        -*$*=;=  -,..~~::-,#    " << endl;                           
 cout <<"             ,@:~--~-.:, ;.        ,-$;=-=,, ~-~,:~;;!@    " << endl;                           
 cout <<"              :@~-*~ ~, ,-         , =;!,.$  .--,~~.:~$    " << endl;                           
 cout <<"               ==;~;,,.        .   , *;~! ;.. ..:,!- #!    " << endl;                           
 cout <<"               .@$ -:.!           .  !.,*-,= ,~~,.:-,@     " << endl;                           
 cout <<"                ,@-.*!,,-         -  :. * ,-.,;:.:..!*     " << endl;                           
 cout <<"                 .@,. -~ ..    .. . ~...!..,--~~.$.~#      " << endl;                           
 cout <<"                  .@# .-..*-.       ~  .-.   ~:!.- @!      " << endl;                           
 cout <<"                   .@.,! *,; .          ...   ;.~ ;=       " << endl;                           
 cout <<"                    .@*# ~:,, ~.-,  .   ~ , . =, !@        " << endl;                           
 cout <<"                     .$;.;--..  . , --. :.:;= -:.#.        " << endl;                           
 cout <<"                      $$ --~;,..-,~:-~-~-;:,..! =:         " << endl;                           
 cout <<"                      =:,,-~=-~:,!:.~;,~,  !    @          " << endl;                           
 cout <<"                      =-,-;;*,;;! -!,:-~..! ! .~@          " << endl;                           
 cout <<"                      $- .,:;-::-- ,-:; ..:*--. @          " << endl;                           
 cout <<"                      #-..;::-:.-..     -:-;    #          " << endl;                           
 cout <<"                      #.  ~-;,.!=      ,,.,.    #          " << endl;                           
 cout <<"                      #  ,.-=$;~*----, - -,-   .@          " << endl;                           
 cout <<"                      @   ,:~~*!!  .,,,, ~     -#          " << endl;                           
 cout <<"                      =    ~,.;,~~-:~-     !,  ,#          " << endl;                           
 cout <<"                     ~-    .,,-=       ,,      .#          " << endl;                           
 cout <<"                     $-    -.;                  -          " << endl;                           
 cout <<"                     =                                     " << endl;                           
 cout <<"                                                           " << endl;
   
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    

