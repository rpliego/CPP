#include <fstream>
#include <iostream>

void	check_errors(std::ofstream &out_file)
{
	if (!out_file.is_open())
	{
		std::cout << "Error opening files" << std::endl;
		exit(1);
	}
}

void	check_errors(std::ifstream &in_file, std::string s1)
{
	if (!in_file.is_open())
	{
		std::cout << "Error opening files" << std::endl;
		exit(1);
	}
	else if (s1.length() == 0)
	{
		std::cout << "s1 cant be empty" << std::endl;
		exit(1);
	}
}

void	replace(std::string s1, std::string s2, std::ifstream &in_file, std::ofstream &out_file)
{
	std::string	line;
	int	i;

	while (std::getline(in_file, line))
	{
		i = line.find(s1);
		while (i >= 0)
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
			i = line.find(s1, i + s2.length());
		}
		out_file << line << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}
	std::string file = av[1];
	std::string s1 = av[2];
	std::string	s2 = av[3];

	std::ifstream in_file(file);
	check_errors(in_file, s1);

	std::ofstream out_file(file += ".replace");
	check_errors(out_file);

	replace(s1, s2, in_file, out_file);

	return (0);
}


// If you can follow this step by step, you will be able to experiment yourself for new edits, maybe you could even find out how to change shinies in the starter menu!

// 1. Open Dev Tools on Chrome (Right click and select inspect, or ctrl + shift + I)
// 2. Find a suitable breakpoint for your needs. To add a breakpoint: right click the short blue dash on the line where your search is.
//   2a. FOR STARTER MENU CANDIES, VOUCHERS, ABILITIES, EGGS RARITY AND HATCH TIMES:
//   Search for 'ShowUseCandies' and add a breakpoint at the line with ShowUseCandies.

//   2b. FOR (CLASSIC/ENDLESS/SPLICED ENDLESS MODE) EGGS RARITY, HATCH TIMES, MONEY, MODIFIERS,    SHINIES, LUCK, VOUCHERS, NATURES etc..
//    Search for 'showmoveselect' and add a breakpoint at line 7510.

// 3a. In order to trigger the breakpoint from 2a, select any starter.
// 3b. In order to trigger the breakpoint from 2b, go to a pokemon summary and click right until you trigger the breakpoint at the moves page.

// 4. Triggering a breakpoint will temporarily pause the game.
// 5. After the game pauses, head over to the console tab.
// 6. Here is where you can put in several commands.
//   6a. The main command we will be using is 'this.scene.gameData'
// 7. First, type 'this.scene.gameData' in the console tab and press enter, and then click on the 'Py...' which contains almost all of the data in your game.

// 8. After clicking on the 'Py...', you will be able to see 4 important menus, 
// eggs, scene, starterData and voucherCounts. If you want to change egg rarity and hatch times, you click on eggs. If you want to unlock candies, abilities and egg moves from the starter menu, click on starterData. If you want to edit your voucher count, click on voucherCounts. I will talk about scene later as scene contains a lot of things you can change, including money, party shinies, luck numbers, and modifiers.

// 9. In order to modify egg rarity, click on any egg in order to drop down the variables for that egg and change your useless commons to powerful legendaries (click on tier and change it from 0 to 3). 1 is for rare and 2 is for epic. In order to change hatchtimes, go to an egg, drop down the variables and change hatchwaves from 100 to 1. This will mean the egg will hatch after 1 more stage.
 
// 10. Changing voucherCounts should be really obvious once you see the menu.

// 11. u/Quizzub talked about the starterData, choose a pokedex number of the starter you want to use in the future, and you can change abilitiesAttr to 7 to unlock all abilities, candycount to 200 is good enough, eggmoves to 15 to unlock all egg moves and change friendship to a suitable value like 90.

// 12. Now we can talk about scene. If you see the 'scene' in bold blue text, click it and you will see many more menus. One of these is money. You can easily change money to whatever you like, even negative numbers so you are in debt! (NOT RECOMMENDED)

// Go to the modifiers menu just above the money variable. It drops down to the perks you currently have on your current run of the game. You can see the name of the perk if you click on anyone of the various perks you have. From this, you can alter the number of e.g Shiny Charms you have. Only thing is that you must have at least 1 in order to change the number. Make sure you don't go over 3 or 5 for most items or 99 for the candy bar.

// You can also change pokeball counts once you find the pokeballCounts menu. 4 is the master ball.

// Try and find the party menu. Once you have found it, you will be able to see the member of your party in code. From here, you can change the IVs, change shiny from false to true, change luck from 0 to 3, and even change the natures of your pokemon. Numbers and their correlation to Natures can be found here: https://bulbapedia.bulbagarden.net/wiki/Nature

// You can also manually change a pokemon's stats but that is (NOT RECOMMENDED)

// After you have changed everything you want to change, remove your breakpoint and unpause your game using the little blue play button by the breakpoint menu. 

// WARNING: Game might start randomly clicking the same button repetitively but it should be easy to stop.

// In order to see certain things, you may need to complete the next stage unless you were in the starter menu. 

// And that's it!