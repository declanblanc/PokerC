These notes are nonsense just a space to think things through 


Card suits can be printed either by directly pasting the symbols ♠ or by their unicode escape sequences \u2660

2spade 0 
2heart 13
2diamond 26
2club 39

dividing any of these by 13 gives a whole number.

Say my hand is 
a straight flush

2 of spades through 6 of spades
This is easy to spot because we have Card0 - Card4 

What if we have a straight that’s not a flush?
For example a straight that starts with the 2 of spades and increases but alternates suits would be:
(card values):
0, 14, 28, 42, 4

Shit this is confusing lol 
These are all divisible by two but I think that's just a coincidence 
Let's try another striaght. 
8H, 9H, 10C, JC, QS
19, 20, 47, 48, 10

Yeah this is meaningless so I think I'll have to look at the actual card values to compare them.

Suits only matter in flushes so for each hand I can check the suit of all the cards and if any don't share the same suit, move on. 


