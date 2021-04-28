# Watopoly
A monopoly, which is similar to the game monopoly with a board based on the University campus.
The following commands can be supplied to command interpreter:

1. roll (used if the player can roll): the player rolls two dice, moves the sum of the two dice and takes action on the square they landed on.
2. next (used if the player cannot roll): give control to the next player.
3. trade <name> <give> <receive>: offers a trade to name with the current player offering give and requesting receive, where give and receive are either amounts of money or a property name. Responses are accept and reject. For example,
4. improve <property> buy/sell: attempts to buy or sell an improvement for property.
5. mortgage <property>: attempts to mortgage property.
6. unmortgage <property>: attempts to unmortgage property.
7. bankrupt: player declares bankruptcy. This command is only available when a player must pay more money then they currently have.
8. assets: displays the assets of the current player. Does not work if the player is deciding how to pay Tuition.
9. all: displays the assets of every player. For verifying the correctness of your transactions. Does not work if a player is deciding how to pay Tuition.
10. save <filename>: saves the current state of the game (as per the description below) to the given file.
