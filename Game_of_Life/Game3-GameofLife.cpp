/* 
------------------------------------------
        This is the Game of Life. 
------------------------------------------

The concept is simple. Born a life with stats, live a life
controlled by the program. With randomness the key aspect, 
can the player survive the ultra randomness life offers..?
After all, life is random generated! */

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
    #include<algorithm> /* algorithm library but are we going to use it? */
/* ----------------------------------------------------- */
/* ----------------------------------------------------- */
/* The classes be defined and declared here. */
/* 1. main_character_setup: this class is where the details of the character
    that is you the player (ofcourse) is going to be stored. */
    class main_character_setup {
        private:
            std::string name, father_name, mother_name; /* The name of the character, duh */
            int age=0;
            int intelligence, looks, craziness;
        public:
            void details_input() {
                std::cout<<"Enter the name: ";
                getline(std::cin,name);

            }
    };
/* ----------------------------------------------------- */

/* ----------------------------------------------------- */
/* The main function be defined here. */
int main(void) {
    return 0;
}
/* ----------------------------------------------------- */