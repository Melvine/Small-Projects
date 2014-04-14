//Melvin Nguyen 04/14/2014
#include <stdio.h>
#include <stdlib.h>

/* This defines a single card.  
 * A card has one of four suits, ranging from 0 to 3:
 * 3 = Spades, 2 = hearts, 1 = diamonds, 0 = clubs
 * A card also has a value, ranging from 0 to 13:
 * 0 = wild card or joker
 * 1 = Ace
 * 2-10 = cards labeled 2-10
 * 11 = jack
 * 12 = queen
 * 13 = king
 */ 

typedef struct _card {
	int suit;
	int value;
} card;

typedef struct _deck {
	int num_cards;
	card *cards;
} deck;

card *make_card(int suit, int value);
deck *make_standard_deck();
int compare(card *c1, card *c2);
int find_index(deck *d, int suit, int value);
void print_card(card *c);

int main(int argc, char *argv[])
{

	card **hand;
	deck *fulldeck;
	int i, j, k;

	/* create an array of card pointers */
	hand = (card **)malloc(sizeof(card *)*5);
	/* make a card for each one */
	for(i=0;i<5;i++)
		hand[i] = make_card(i%4, (i*17)%14);
	
	/* print out the cards in the hand */
	printf("Hand: ");
	for(i=0;i<5;i++)
 		print_card(hand[i]);
	printf("\n"); 

	/* make a standard deck of cards */
	fulldeck = make_standard_deck();
	if (fulldeck == NULL)
	{
		printf("make_standard_deck not yet implemented ... exiting\n");
		exit(0);
	}
	/* print out all of the cards */
	for(i=0;i<fulldeck->num_cards;)
		for(j=0;j<13 && i<fulldeck->num_cards;j++,i++)
		 	print_card(&(fulldeck->cards[i]));
	

	/* compare some cards */
	printf("Compare: ");
	print_card(&(fulldeck->cards[5]));
	print_card(&(fulldeck->cards[17]));
	printf(": %d\n",compare(&(fulldeck->cards[5]),&(fulldeck->cards[17])));

	printf("find index: C 5: %d", find_index(fulldeck,0,5));

}

/* make_card
 *
 * Allocate space for AND initialize the values for a single card
 */
card *make_card(int suit, int value)
{
	card *newCard = malloc(sizeof(card)); 
  newCard->value = value;
  newCard->suit = suit;
  return newCard;
}

/* make_standard_deck
 *
 * Create a full standard deck.  A standard deck contains 52 cards - 
 * for each suit, it contains an Ace through a King.  Not including
 * any wild cards or jokers
 *
 * Allocate all of the necessary space for the entire 
 * deck - the deck and all of the cards - and initialize all values
 * of all of the structures you allocate.
 *
 */

deck *make_standard_deck()
{
	deck *newDeck = malloc(sizeof(deck));
  int i,s =0,v =1;

  newDeck->num_cards = 52 ;
  newDeck->cards = make_card(s, v);

  for(i = 0;i  <= 51; i++){
    if(s == 4){
      s = 0; //max suit is 4, must reset to 0 to 3 only.
      v++;   //next value in the deck after all suits of the current card
    }
    
    //allocates a new card til 52 unique cards are made
    newDeck->cards[i] = *make_card(s, v);
    s++;
  }
  
  return newDeck;
}
/* compare
 *
 * Compare two cards.  Compare cards to first look at the value.  
 * If the values are different, then the card with the higher value
 * is higher.  If the values are the same, then we check the suit.  The vard
 * with a suit with a higher value (0-3) is higher.
 *
 * The compare result is -1, 0, or 1.  If c1 < c2, then return -1.  If
 * c1 == c2, then return 0.  If c1 > c2, then return 1.
 */
int compare(card *c1, card *c2)
{
	//checking if either card is greater than the other
  if((c1->value) < (c2->value)){
    return -1;
  }
  else if((c1->value) > (c2->value)){
    return 1;
  }
  
  //since both values are equal at this point, check suit for differences
  if((c1->suit) == (c2->suit)){
    return 0;
  }
  else if((c1->suit) < (c2->suit)){
    return -1;
  }
  else if((c1->suit) > (c2->suit)){
    return 1;
  }
}
/* find_index
 *
 * Find the index of a card in the deck.  This looks in the cards array and
 * returns the index of the corresponding card.  If the card is not present,
 * it returns -1.
 */
int find_index(deck *d, int suit, int value)
{
	int i;
  for(i=0;i<=51;i++){
    if(d->cards->value == value && d->cards->suit == suit)
      return i;
    d->cards++;
  }
   return -1;
}

/* *********** DO NOT CHANGE CODE BELOW THIS LINE *************** */
/* This code *will* go into problem1helpers.c */

void print_card(card *c)
{
	char *suitchars = "CDHS";
	char *valuechars = "WA23456789TJQK";
	if (c == NULL)
	{
		printf("Card is not allocated\n");
		return;
	}
	if ((c->suit < 0) || (c->suit > 3))
		printf("Invalid suit: %d\n",c->suit);
	else if ((c->value < 0) || (c->value > 13))
		printf("Invalid value: %d\n",c->value);
	else
		printf("%c %c ", suitchars[c->suit], valuechars[c->value]);
}
