// Copyright (c) 2021 Ketia Gaelle Kaze All rights reserved.
//
// Created by: Ketia Gaelle Kaze
// Created on: Jan. 11, 2022
// This program asks the user to enter a whole number
// and then uses the loop to calculate and display the
// square of all numbers from 0 to the user number.
# include <iostream>
# include <random>

int main() {
    // initialize the loop counter
    int loopCounter = 0;
    int guessedNumber;
    int randomNumber;
    std::string guessedNumberString;

    // generate random number
    int someRandomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    someRandomNumber = idist(rgen);

    while (true) {
        // get the guessed number as string
        std::cout <<"Guess a number between 0 and 9: ";
        std::cin >> guessedNumberString;

        try {
            // checks for errors
            guessedNumber = std::stoi(guessedNumberString);

            // check to see if the guessed number is in range 0 and 9
            if (guessedNumber >= 0 && guessedNumber <= 9) {
                // counter incrementation
                loopCounter = loopCounter + 1;
                if (guessedNumber == randomNumber) {
                    // Display the result
                    std::cout << "" << std::endl;
                    std::cout <<"Your guess is correct! Thanks for playing!";
                    break;

                } else {
                    std::cout << "" << std::endl;
                    std::cout <<"Your guess is wrong. The correct number is "
                        <<randomNumber<< "\n";
                    std::cout << std::endl;
                    std::cout << "Tracking "<< loopCounter <<
                        " times through the loop.\n";
                    std::cout << std::endl;
                }
            } else {
                std::cout << "" << std::endl;
                std::cout <<guessedNumber<< " is not in the range of numbers "
                << "to guess from. Please try again" "\n";
                std::cout << "" << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "" << std::endl;
            std::cout <<guessedNumberString<< " is not a number. "
            << "Please try again. " "\n";
             std::cout << "" << std::endl;
        }
    }
}

