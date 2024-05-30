/**
 * Project p_representation
 * @author p
 */


#ifndef _ADDRESSBOOK_H
#define _ADDRESSBOOK_H

#include "Contact.h"


class AddressBook: public Contact {
public: 
    
/**
 * @param name
 */
bool exist_contact(char* name);
    
/**
 * @param someone
 */
Contact** list_friends(Contact* someone);
    
/**
 * @param name
 */
bool delete_contact(void name);
    
/**
 * @param name
 */
bool add_contact(char* name);
private: 
    Contact** all_contancts;
};

#endif //_ADDRESSBOOK_H