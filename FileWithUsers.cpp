#include "PlikiZUsers.h"

vector <User> PlikiZUsers::loadUsersFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;
    xml.Load( NAME_FILE_USERS );
    xml.FindElem("USERS");
    xml.IntoElem();
    while ( xml.FindElem("USER") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        user.ustawID(nUserID);
        xml.FindElem("NAME");
        MCD_STR strName = xml.GetData();
        user.ustawImie(strName);
        xml.FindElem("SURNAME");
        MCD_STR strSurname = xml.GetData();
        user.ustawNazwisko(strSurname);
        xml.FindElem("LOGIN");
        MCD_STR strLogin = xml.GetData();
        user.ustawLogin(strLogin);
        xml.FindElem("PASSWORD");
        MCD_STR strPassword = xml.GetData();
        user.ustawHaslo(strPassword);
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}
void PlikiZUsers::appendUserToFile(User user) {
    CMarkup xml;
    if(xml.Load( NAME_FILE_USERS )==false) {
        xml.AddElem( "USERS" );
        xml.IntoElem();
        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem( "USERID", user.pobierzID() );
        xml.AddElem( "NAME", user.pobierzImie() );
        xml.AddElem( "SURNAME", user.pobierzNazwisko() );
        xml.AddElem( "LOGIN", user.pobierzLogin() );
        xml.AddElem( "PASSWORD", user.pobierzHaslo() );

        xml.OutOfElem();
        xml.Save( NAME_FILE_USERS );
    } else {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem( "USERID", user.pobierzID() );
        xml.AddElem( "NAME", user.pobierzImie() );
        xml.AddElem( "SURNAME", user.pobierzNazwisko() );
        xml.AddElem( "LOGIN", user.pobierzLogin() );
        xml.AddElem( "PASSWORD", user.pobierzHaslo() );
        xml.OutOfElem();
        xml.Save( NAME_FILE_USERS );
    }
}

void PlikiZUsers::saveAllUsersToFile(vector <User> &users) {
    vector <User>::iterator itrKoniec = --users.end();
    CMarkup xml;
    xml.AddElem( "USERS" );
    xml.IntoElem();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem( "USERID", itr->pobierzID() );
        xml.AddElem( "NAME", itr ->pobierzImie() );
        xml.AddElem( "SURNAME", itr ->pobierzNazwisko() );
        xml.AddElem( "LOGIN", itr ->pobierzLogin() );
        xml.AddElem( "PASSWORD", itr ->pobierzHaslo() );
        xml.OutOfElem();
    }
    xml.Save( NAME_FILE_USERS );
}
