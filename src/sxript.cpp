#include "sxript.h"

int main(int argc, char* argv[]) {
	
    // '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

    SxriptLogoSize = 0;
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "                  .      ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "    +@@@@,        @@     ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "   @@@@@@@'       @@@:   ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "  @@@@@@@@@      +@@@@@: ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "  #    @@@@#     @@@@@@  ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "       ,@@@@    .++@@@+  ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "        @@@@#   @    @   ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "        ;@@@@  ,@        ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "         @@@@# @         ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "         #@@@@'@         ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "          @@@@@,         ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "      '###@@@@@#######   ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "      @@@@@@@@@@@@@@@.   ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "     .@@@@@@@@@@@@@@@    ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "      ``....@@@@#        ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "           ,@@@@@        ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "           @`@@@@#       ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "          `@ @@@@@       ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "          @;  @@@@'      ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "          @   @@@@@      ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "    @;   #+   `@@@@'     ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "   ,@@@' @     @@@@@     ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "   @@@@@@@     .@@@@; +  ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "   @@@@@@       @@@@@@+  ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "    +@@@@       .@@@@#   ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "      @@.        #@@@    ";
    SxriptLogoSize = SxriptLogoSize + 1;
    SxriptLogoText[SxriptLogoSize] = "       `          `+     ";

    FunctionListSize = 0;
    VariableListSize = 0;
    ScopeLevel = 1;

    BrackList = "`',()<>[]{}";
    OpList = "!^*/%+-=&|~?";
    EscapeChar = "\\";

    int kt;
    std::string at;
    std::string bt;
    at = "<";
    for (kt = 1; kt <= SxriptLogoSize; kt += 1) {
        bt = SxriptLogoText[kt];
        bt = replaceRaw(bt, "`", cHR(26));
        bt = replaceRaw(bt, cHR(26), EscapeChar + "`");
        bt = replaceRaw(bt, "'", cHR(26));
        bt = replaceRaw(bt, cHR(26), EscapeChar + "'");
        bt = "`" + bt + "'";
        at = at + bt;
        if (kt < SxriptLogoSize) {
            at = at + ",";
        }
    }
    at = at + ">";
    at = sxriptEval("let(sxlogo," + at + ")");
	
    std::string UserInput;

    if (argc > 1) { 
        UserInput = argv[1];
        std::cout << sxriptEval(UserInput) << "\n";
        return 0;
    }

    std::cout << "\n";
    std::cout << "\n";

    int kglob;
    for (kglob=1; kglob<= SxriptLogoSize; kglob += 1) {
        std::cout << SxriptLogoText[kglob];
        std::cout << "\n";
    }
    
    std::cout << " *** Welcome to Sxript *** \n";
    std::cout << "        (C++ Build)        \n";
    std::cout << "\n";

    do {
        std::cout << ":";
        std::getline (std::cin, UserInput);
        std::cout << ":" << sxriptEval(UserInput) << "\n\n";

    } while (1 == 1);

    return 0;

}


