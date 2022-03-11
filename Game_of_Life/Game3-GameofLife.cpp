/* 
------------------------------------------
        This is the Game of Life. 
------------------------------------------

The concept is simple. Born a life with stats, live a life
controlled by the program. With randomness the key aspect, 
can the player survive the ultra randomness life offers..?
After all, life is random generated! */

/* ----------------------------------------------------- */
/* Any links or extra header files reference be here */

/* ----------------------------------------------------- */

/* ----------------------------------------------------- */
/* The header files and future global variables be here */
    #include<iostream> /* IO stream */
    #include<math.h> /* math header */
    #include<string> /* string functions */ 
    #include<cstdlib> /* standard library */
    #include<ctime> /* Time library */
    #include<random> /* For the engine */
    #include<utility> /* Utility for unrelated domains*/
    #include<functional> /* Functional object for standard hash function*/
    #include<vector> /* Vector functions header */
    #include<fstream> /* File operations in C++ */
    #include<algorithm> /* algorithm library but are we going to use it? */
/* ----------------------------------------------------- */
/* ----------------------------------------------------- */
/* The classes be defined and declared here. */
/* 1. main_character_setup: this class is where the details of the character
    that is you the player (ofcourse) is going to be stored. */
    
    class main_character_setup {
        private:
            /* List of variables and (if needed) functions in the private access-specifier */
            /* 1. Game and Control Related */
                int start_up_game_choice; /* Variable to choose mode of game*/
            /* 2. Character related variables*/
                std::string main_character_name; /* The name of the character, duh*/
                int main_character_age=0; /* The age of the character */
                int main_character_intelligence, main_character_looks, main_character_health, main_character_mindframe; /* The character's stats */
                int main_character_gender=0; /* Start binary in life */
                double main_character_money=0.0; /* Born in rags, got to wait either for a metal or a silver or no spoon */
        public:
            /* List of functions in the public access-specifier */
            /* 1. start_up() - function gives option if character needs to be generated or user-input. 
               2. start_up_game() - function to generate the random name and stats 
                   Depending functions: 2.1: reading_names(&file_name):  */
            
            /* Function 2.1 */
            static std::vector<std::string> reading_names(const std::string &file_name) {
                std::vector<std::string> names;
                std::ifstream file(file_name);
                for(std::string name; std::getline(file_name, name) && !name.empty(); names.push_back(std::move(name)));
                return names;             
            }
            
            /* Function 2 */
            void start_up_game() {
                /* This function sets up the character's details and stats */
                /* using a dummy variable to action the next set of steps called dummy_start */
                /* if choice is 1, random mode */
                int dummy_start=start_up();
                if(dummy_start==1) {
                    /* This is the random mode */
                    std::random_device rd; /* Random mode*/
                    std::uniform_int_distribution<int> dist(0,3); /* Setting limit for genders - Code 
                    0 - Neutral (:|) 1 - Male 2 - Female 3 - Alien */
                    main_character_gender=dist(rd); /* Setting gender*/
                    switch(main_character_gender) {
                        case 0: 
                                break;
                        case 1: 

                    }
                }
            }

            /* Function 1 */
            int start_up() {
                /* This function 1. introduces the player to choose an option regarding the status of his game */
                std::cout<<"\tGame of Life!"<<std::endl;
                std::cout<<"-----------------------------"<<std::endl;
                std::cout<<"\n1. Generated Names \n2. User-Input Names"<<std::endl;
                std::cin>>start_up_game_choice;
                return start_up_game_choice; /* This value is used in the function 2. start_up_game() */
            }
            
    };
/* ----------------------------------------------------- */

/* ----------------------------------------------------- */
/* The main function be defined here. */
int main(void) {
    return 0;
}
/* ----------------------------------------------------- */