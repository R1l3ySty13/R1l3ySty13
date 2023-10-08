#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#define FILENAME "Juventus_database.csv"

//function declarations
void file_check();
int file_viewer();
int append_players();
int edit_player_data();
int main();


void file_check() {
    std::ifstream file(FILENAME);
    
    if (!file) {
        std::ofstream createFile(FILENAME);
        if (createFile) {
            createFile.close();
        }
        else {
            std::cerr << "Error creating the file." << std::endl;
        }
    }
}

int file_viewer() {
    std::cout << "\n\n\n\n" << std::endl;

    std::ifstream inFS;
    std::string lineData, delimiter = ",";
    
    file_check();
    
    inFS.open(FILENAME);

    if (!inFS.is_open()) {
        std::cout << "Failed to open database." << std::endl;
        return 1;
    }

    // Print headers
    std::cout << std::left << std::setw(15) << "First Name"
              << std::left << std::setw(15) << "Last Name"
              << std::left << std::setw(5) << "Age"
              << std::left << std::setw(15) << "Position"
              << std::left << std::setw(15) << "Nationality"
              << std::left << std::setw(5) << "Goals"
              << std::left << std::setw(5) << "Assists" << std::endl << std::endl;

    while (std::getline(inFS, lineData)) {
        std::stringstream ss(lineData);
        std::string field;

        // Initialize variables for player data
        std::string first_name, last_name, age, position, nationality, goals, assists;

        // Use a loop to extract all fields
        int fieldCount = 0;
        while (std::getline(ss, field, ',')) {
            switch (fieldCount) {
                case 0: first_name = field; break;
                case 1: last_name = field; break;
                case 2: age = field; break;
                case 3: position = field; break;
                case 4: nationality = field; break;
                case 5: goals = field; break;
                case 6: assists = field; break;
            }
            fieldCount++;
        }

        // Print player data with formatting
        std::cout << std::left << std::setw(15) << first_name
                  << std::left << std::setw(15) << last_name
                  << std::left << std::setw(5) << age
                  << std::left << std::setw(15) << position
                  << std::left << std::setw(15) << nationality
                  << std::left << std::setw(5) << goals
                  << std::left << std::setw(5) << assists << std::endl;
    }

    return 0;
}


int append_players () {
    std::cout << "\n\n\n\n" << std::endl;
    int j = 1;

    std::string playerFirstname , playerLastname , playerPos , player_nationality , age , teamNumber, goals, assists;

    std::ofstream playerInfo(FILENAME , std::ios::app);

    if (!playerInfo) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }
    //while loop to begin iterating appending players into csv file

    while (j == 1) {
        //Gather players name from input
        std::cout << "Please enter player's first and last name seperated by a space: " << std::endl;
        std::cin >> playerFirstname >> playerLastname;

        //Gather nationality from input
        std::cout << "What is " << playerFirstname << " " << playerLastname << "'s nationality?" << std::endl;
        std::cin >> player_nationality;

        //Gather player age from input
        std::cout << "How old is " << playerFirstname << " " << playerLastname << " ?" << std::endl;
        std::cin >> age;

        //Gather player number from input
        std::cout << "What is " << playerFirstname << " " << playerLastname << "'s jersey number?" << std::endl;
        std::cin >> teamNumber;

        //Gather player position from input
        std::cout << "What position does " << playerFirstname << " " << playerLastname << "play? Enter (CB CDM ST) : " << std::endl;
        std::cin >> playerPos;

        //Gather player goals from input
        std::cout << "How many goals " << playerFirstname << " " << playerLastname << " scored?";
        std::cin >> goals;

        //Gather player assists from input
        std::cout << "How many assists has " << playerFirstname << " " << playerLastname << " contributed?" << std::endl;
        std::cin >> assists;

        //Write appended info into the player database
        playerInfo << playerFirstname << "," << playerLastname << "," << age << "," << player_nationality << "," << playerPos << "," << teamNumber << "," << goals << "," << assists << std::endl;

        std::cout << "New player profile successfully created!" << std::endl;

        std::cout << "Would you like to create an additional player profile? \nYes : 1 \n No : 2" << std::endl;
        std::cin >> j;

    }
    playerInfo.close();
    return 0;
}

int edit_player_data() {
    return 0;
}

int menu() {
    
    std::string input;
    while (!(input == "q" || input == "quit" || std::cin.eof())) {
        std::cout << std::setfill('-') << std::setw(44) << std::endl;
        std::cout << std::setfill(' ') << std::setw(34) << std::right << "Juventus Player Database" << std::endl;
        std::cout << "\n\n" << std::endl;
        std::cout << "1. View Player Data" << std::endl;
        std::cout << "2. Append Player Data" << std::endl;
        std::cout << "3. Edit Existing Player Info" << std::endl;
        std::cout << std::endl;

        if (input == "1") {
            file_viewer();
        }
        else if (input == "2") {
            append_players();
        }
        else if (input == "3") {
            edit_player_data();
        }

        std::cout << std::endl;
        std::cout << "What would you like to do? (Enter q or ctrl + d or quit to quit) : ";
        std::cin >> input;
    }
    return 0;
}

int main() {
    menu();
}