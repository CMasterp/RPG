/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "../include/rpg.h"

void init_name(void)
{
    info.name[0][0] = '\0';
    my_catt(info.name[0], "Rock");
    info.name[1][0] = '\0';
    my_catt(info.name[1], "Lea");
    info.name[2][0] = '\0';
    my_catt(info.name[2], "Francesca");
    info.name[3][0] = '\0';
    my_catt(info.name[3], "Shinki");
    info.name[4][0] = '\0';
    my_catt(info.name[4], "Prince");
    info.name[5][0] = '\0';
    my_catt(info.name[5], "Sharonse");
    info.name[6][0] = '\0';
    my_catt(info.name[6], "Phoebe");
    info.name[7][0] = '\0';
    my_catt(info.name[7], "Basilia");
    info.name[8][0] = '\0';
    my_catt(info.name[8], "Grimor");
    info.name[9][0] = '\0';
    my_catt(info.name[9], "Anne");
}

void init_att(void)
{
    info.att[0] = 550;
    info.att[1] = 250;
    info.att[2] = 440;
    info.att[3] = 570;
    info.att[4] = 520;
    info.att[5] = 530;
    info.att[6] = 350;
    info.att[7] = 490;
    info.att[8] = 560;
    info.att[9] = 250;
}

void init_exp(void)
{
    info.exp[0] = 500;
    info.exp[1] = 200;
    info.exp[2] = 450;
    info.exp[3] = 510;
    info.exp[4] = 550;
    info.exp[5] = 500;
    info.exp[6] = 300;
    info.exp[7] = 470;
    info.exp[8] = 500;
    info.exp[9] = 200;
}

void init_def(void)
{
    info.def[0] = 650;
    info.def[1] = 150;
    info.def[2] = 350;
    info.def[3] = 450;
    info.def[4] = 500;
    info.def[5] = 550;
    info.def[6] = 250;
    info.def[7] = 400;
    info.def[8] = 500;
    info.def[9] = 200;
}

void init_info(void)
{
    init_name();
    init_exp();
    init_att();
    init_def();
    vie = 1000;
}
