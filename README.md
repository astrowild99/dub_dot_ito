# Dub.ito
This is a simple c++ implementation of the not-so-famous
`dubito` italian game.  
It is a simple trust game run with 4->10 people, played
with a single deck of french cards (red or blue).  

## Rules
The rules of the game are pretty straight forward:
- all the cards are distributed between players at the beginning.
- the first to play, the one right after the dealer, puts 1 to 3 cards
hidden on the playing table, and declares the value of the card. (e.g. 7)
- the next in turn can either:
  - play 1 to 3 cards, declaring the value is the same of the hidden ones.
  - doubt that the player before that declared the true cards.
- when player B doubts, the cards that player A put are exposed:
  - if all the cards have the value declared, player B gets all the cards on the table.
  - otherwise, player A takes back all the cards on the table
  - jolly is treated as the card declared, and is burned if "exposed"
- when a player has 4 cards of the same value, these are burned

## Goal
The goal is to be the first without cards

# Target
The goal of the project is to improve c++ skills, and to use all the best practices
of oop programming:
- **SOLID** principles
- design patterns
- separation of concerns
- etc...

