// Cards.cpp
// Implements Cards and Poker Hand functionality
#include "Cards.h"
#include <random>
#include <algorithm>

// Function: Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them
// by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(ITPVector<Card>& deck)
{
    for (int i = 0; i < 5; i++)
    {
        Card temp = deck.get_back(); // temp card to hold last card of deck
        mHand.insert_back(temp); // put temp card into back of hand
        deck.remove_back(); // take card out of deck to make sure no repeats
    }

	// Sort the hand
	std::sort(&mHand[0], &mHand[0] + mHand.size());
}

// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand
// contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
    if (this->hasStraight() && this->hasFlush() && this->mHand[0].mRank == 10)
    {
        return "ROYALLLLLLLLLLLLLLLLLLLL FLUUSH";
    }
    if (this->hasStraight() && this->hasFlush())
    {
        return "STRAIGHT FLUSH";
    }
    if (this->hasFourOfAKind())
    {
        return "FOUR OF A KIND";
    }
    if (this->hasFullHouse())
    {
        return "FULL HOUSE!!!";
    }
    if (this->hasFlush())
    {
        return "FLUSH";
    }
    if (this->hasStraight())
    {
        return "STRAIGHT";
    }
    if (this->hasThreeOfAKind())
    {
        return "THREE OF A KIND!";
    }
    if (this->hasTwoPairs())
    {
        return "Two Pair!";
    }
    if (this->hasPair())
    {
        return "pair.";
    }
    return "high card."; // last possible hand since it can't be any of the above
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
	bool retVal = false;
    
    if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank+1 &&
        mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank+1 &&
        mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank+1 &&
        mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank+1)
    {
        retVal = true;
    }
    
	return retVal;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{
	bool retVal = false;
    
    if (mHand[mHand.size()-1].mSuit == mHand[mHand.size()-2].mSuit &&
        mHand[mHand.size()-2].mSuit == mHand[mHand.size()-3].mSuit &&
        mHand[mHand.size()-3].mSuit == mHand[mHand.size()-4].mSuit &&
        mHand[mHand.size()-4].mSuit == mHand[mHand.size()-5].mSuit)
    {
        retVal = true;
    }
    
	return retVal;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
	bool retVal = false;
    if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank &&
        mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank &&
        mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank)
    {
        retVal = true;
    }

    if (mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank &&
        mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank &&
        mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank)
    {
        retVal = true;
    }
	

	return retVal;
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
	bool retVal = false;
    
    if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank &&
        mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank &&
        mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank)
    {
        retVal = true;
    }
    
    else if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank &&
        mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank &&
        mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank)
    {
        retVal = true;
    }
    
	return retVal;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
	bool retVal = false;
	
    if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank &&
        mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank)
    {
        retVal = true;
    }
    if (mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank &&
        mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank)
    {
        retVal = true;
    }
    if (mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank &&
        mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank)
    {
        retVal = true;
    }
	return retVal;
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{

	bool retVal = false;
	
    if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank &&
        mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank)
    {
        retVal = true;
    }
    if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank &&
        mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank)
    {
        retVal = true;
    }
    if (mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank &&
        mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank)
    {
        retVal = true;
    }
	return retVal;
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
    bool retVal = false;
    if (mHand[mHand.size()-1].mRank == mHand[mHand.size()-2].mRank)
    {
        retVal = true;
    }
    if (mHand[mHand.size()-2].mRank == mHand[mHand.size()-3].mRank)
    {
        retVal = true;
    }
    if (mHand[mHand.size()-3].mRank == mHand[mHand.size()-4].mRank)
    {
        retVal = true;
    }
    if (mHand[mHand.size()-4].mRank == mHand[mHand.size()-5].mRank)
    {
        retVal = true;
    }
    return retVal;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Do not edit code below this line!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a
// standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(ITPVector<Card>& deck)
{
	for (int i = 0; i < 4; i++)
	{
		Suit suit = Suit(i);
		for (int value = 2; value <= 14; value++)
		{
			deck.insert_back(Card(value, suit));
		}
	}

	// Shuffle the deck
	std::shuffle(&deck[0], &deck[0] + deck.size(), std::random_device());
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
	// Output value
	if (card.mRank < 11) // Number card
	{
		os << card.mRank;
	}
	else // Face card
	{
		switch (card.mRank)
		{
		case 11:
			os << "Jack";
			break;
		case 12:
			os << "Queen";
			break;
		case 13:
			os << "King";
			break;
		case 14:
			os << "Ace";
			break;
		default:
			os << "Invalid";
			break;
		}
	}

	// Output suit
	os << " of ";
	switch (card.mSuit)
	{
	case CLUBS:
		os << "Clubs";
		break;
	case DIAMONDS:
		os << "Diamonds";
		break;
	case HEARTS:
		os << "Hearts";
		break;
	case SPADES:
		os << "Spades";
		break;
	default:
		os << "Invalid";
		break;
	}

	return os;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
	// If their values are the same, compare the suits
	if (left.mRank == right.mRank)
	{
		return left.mSuit < right.mSuit;
	}
	else
	{
		return left.mRank < right.mRank;
	}
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
	os << hand.mHand;
	return os;
}
