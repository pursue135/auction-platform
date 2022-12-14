#include "mainIntfFunc.h"
#include "menuNumber.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

inline void prompt();
inline void promptAdm();
inline void promptUser();
inline void promptSeller();
inline void promptBuyer();
inline void promptPersonalInfo();
void enterAdmIntf(Administrator *);
void enterUserIntf(User *);
void checkAuctionExpired();

extern  char  starStr[];
static char str[120] = "===================================================================================="
"================";
void mainIntf()
{
    int seq;
    Administrator *adm;
    User *user;
    while (1)
    {
        file.checkCommExpired();
        prompt();
        cin >> seq;
        char ch = getc(stdin);
        ungetc(ch, stdin);
        if (cin.fail() || ch != '\n')
        {
            //exitRun();
            cout << "输入不合法，请输入正确的操作编号！" << endl << endl;
            cin.clear();
            cin.ignore(HUGE_NUM, '\n');
            continue;
        }
        cin.ignore(HUGE_NUM, '\n');
        switch (seq)
        {
        case ADM_LOG_IN:
            adm = admLogin();
            if (adm)
                enterAdmIntf(adm);
            break;
        case USER_SIGN_IN:
            signIn();
            break;
        case USER_LOG_IN:
            user = userLogin();
            if (user)
                enterUserIntf(user);
            break;
        case EXIT:
            return;
        default:
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
        }
    }
}

void enterAdmIntf(Administrator *adm)
{
    int seq;
    while (1)
    {
        file.checkCommExpired();
        promptAdm();
        cin >> seq;
        char ch = getc(stdin);
        ungetc(ch, stdin);
        if (cin.fail() || ch != '\n')
        {
            //exitRun();
            cout << "输入不合法，请输入正确的操作编号！" << endl<< endl;
            cin.clear();
            cin.ignore(HUGE_NUM, '\n');
            continue;
        }
        cin.ignore(HUGE_NUM, '\n');
        switch (seq)
        {
        case ADM_VIEW_ALL_COMMS:
            adm->viewCommodities();
            break;
        case ADM_SEARCH_COMM:
            adm->searchCommodities();
            break;
        case ADM_PULL_COMM:
            adm->pullCommodity();
            break;
        case ADM_VIEW_ALL_ORDERS:
            adm->viewOrders();
            break;
        case ADM_VIEW_ALL_USERS:
            adm->viewUsers();
            break;
        case ADM_BAN_USER:
            adm->banUser();
            break;
        case  ADM_UNBAN_USER:
            adm->unbanUser();
            break;
        case ADM_VIEW_BANNED_USERS:
            adm->viewAllBannedUsers();
            break;
        case ADM_LOG_OUT:
            return;
        default:
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
        }
    }
}

void enterBuyerIntf(User *user)
{
    int seq;
    while (1)
    {
        file.checkCommExpired();
        promptBuyer();
        cin >> seq;
        char ch = getc(stdin);
        ungetc(ch, stdin);
        if (cin.fail() || ch != '\n')
        {
            //exitRun();
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
            cin.clear();
            cin.ignore(HUGE_NUM, '\n');
            continue;
        }
        cin.ignore(HUGE_NUM, '\n');
        switch (seq)
        {
        case BUYER_VIEW_COMM_LIST:
            user->viewAllComms();
            break;
        case BUYER_AUCTION_COMM:
            user->auction();
            break;
        case BUYER_SEARCH_COMM:
            user->searchCommodity();
            break;
        case BUYER_VIEW_ORDERS:
            user->viewBuyerOrders();
            break;
        case BUYER_VIEW_COMM_DETAIL:
            user->viewCommDetail();
            break;
        case BUYER_MODIFY_AUCTION:
            user->modifyAuction();
            break;
        case BUYER_AUCTION_INFO:
            user->viewAllAuctions();
            break;
        case BUYER_BACK_TO_USER_INTF:
            return;
        default:
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
        }
    }
}

void enterSellerIntf(User *user)
{    
    int seq;
    while (1)
    {
        file.checkCommExpired();
        promptSeller();
        cin >> seq;
        char ch = getc(stdin);
        ungetc(ch, stdin);
        if (cin.fail() || ch != '\n')
        {
            //exitRun();
            cout << "输入不合法，请输入正确的操作编号！" << endl<< endl;
            cin.clear();
            cin.ignore(HUGE_NUM, '\n');
            continue;
        }
        cin.ignore(HUGE_NUM, '\n');
        switch (seq)
        {
        case SELLER_RELEASE_COMM:
            user->releaseCommodity();
            break;
        case SELLER_VIEW_RELEASED_COMM:
            user->viewReleasedComm();
            break;
        case SELLER_MODIFY_COMM_INFO:
            user->modifyCommInfo();
            break;
        case SELLER_PULL_COMM:
            user->pullCommodity();
            break;
        case SELLER_VIEW_ORDERS:
            user->viewSellerOrders();
            break;
        case SELLER_PUTAWAY_COMM:
            user->putawayComm();
            break;
        case SELLER_BACK_TO_USER_INTF:
            return;
        default:
            cout << "输入不合法，请输入正确的操作编号！" << endl << endl;
        }
    }
}

void enterInfoManageIntf(User *user)
{
    int seq;
    while (1)
    {
        file.checkCommExpired();
        promptPersonalInfo();
        cin >> seq;
        char ch = getc(stdin);
        ungetc(ch, stdin);
        if (cin.fail() || ch != '\n')
        {
        //exitRun();
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
            cin.clear();
            cin.ignore(HUGE_NUM, '\n');
            continue;
            ;
        }
        cin.ignore(HUGE_NUM, '\n');
        switch (seq)
        {
        case VIEW_INFO:
            user->viewUserInfo();
            break;
        case MODIFY_INFO:
            user->modifyUserInfo();
            break;
        case TOP_UP:
            user->topUp();
            break;
        case MODIFY_PASSWD:
            user->modifyPasswd();
            break;
        case BACK_TO_USER_INTF:
            return;
        default:
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
        }
    }
}

void enterUserIntf(User *user)
{
    int seq;
    while (1)
    {
        file.checkCommExpired();
        promptUser();
        cin >> seq;
        char ch = getc(stdin);
        ungetc(ch, stdin);
        if (cin.fail() || ch != '\n')
        {
            //exitRun();
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
            cin.clear();
            cin.ignore(HUGE_NUM, '\n');
            continue;
            ;
        }
        cin.ignore(HUGE_NUM, '\n');
        switch (seq)
        {
        case BUYER_ROLE:
            enterBuyerIntf(user);
            break;
        case SELLER_ROLE:
            enterSellerIntf(user);
            break;
        case PERSONAL_INFO_MANAGEMENT:
            enterInfoManageIntf(user);
            break;
        case USER_LOG_OUT:
            logout(nullptr, user);
            return;
        default:
            cout << "输入不合法，请输入正确的操作编号！" << endl
                 << endl;
        }
    }
}

inline void prompt()
{
    cout << str << endl;
    cout << "                  1.管理员登陆    2.用户注册  3.用户登陆  4.退出程序"<< endl;
    cout << str << endl;
    cout <<  "请输入要进行的操作的编号:  ";
}

inline void promptAdm()
{
    cout << str << endl;
    
    cout << "1.查看所有商品" << endl;
    cout << "2.搜索商品"<<endl;
    cout << "3.下架商品 "  << endl;
    cout << "4.查看所有订单" << endl;
    cout << "5.查看所有用户" << endl;
    cout << "6.封禁用户 "<< endl;
    cout << "7.查看被封禁用户" << endl;
    cout << "8.解封用户" << endl;
    cout << "9.注销"  << endl;
    cout << str << endl;
    cout << "请输入要进行的操作的编号：";
}

inline void promptUser()
{
    cout << str << endl;
    cout << "       1.我是买家     2. 我是卖家     3.个人信息管理      4.注销登陆" << endl;
    cout << str << endl;
    cout << "请输入要进行的操作的编号：" ;
}

inline void promptSeller()
{
    cout << str <<endl;
    cout << "1.发布商品" << endl;
    cout << "2.查看发布商品"<< endl;
    cout << "3.修改商品信息" << endl;
    cout << "4.下架商品" << endl;
    cout << "5.查看历史订单" << endl;
    cout << "6.重新上架商品" << endl;
    cout << "7.返回用户主界面" << endl;
    cout << str << endl;
    cout << "请输入要进行的操作的编号：";
}

inline void promptBuyer()
{
    cout << str <<endl;
    cout << "1.查看商品列表" << endl;
    cout << "2.竞拍商品" << endl;
    cout << "3.搜索商品" << endl;
    cout << "4.查看历史订单 " << endl;
    cout << "5.查看商品详细信息"<< endl;
    cout << "6.修改竞拍"<< endl;
    cout << "7.查看竞拍信息"<<endl;
    cout << "8.返回用户主界面" << endl;
    cout << str <<endl;
    cout << "请输入要进行的操作的编号：";
}

inline void promptPersonalInfo()
{
    cout << str << endl;
    cout << "       1.查看信息      2.修改信息      3.充值      4.修改密码      5.返回用户主界面" << endl;
    cout << str << endl;
    cout << "请输入要进行的操作的编号：";
}

