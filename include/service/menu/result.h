#ifndef RESULT_H
#define RESULT_H
#include<QMessageBox>
#include<QWidget>
class Result{
private:
    QWidget *parant = nullptr;
public:
    Result(QWidget *parant):parant(parant){};

    void Input_over_len(){
         QMessageBox::critical(parant, QString("Error"), QString("输入的卡号或密码过长!(卡号最长18位，密码最长9位)"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void Input_no_num(){
         QMessageBox::critical(parant, QString("Error"), QString("金额必须是数字，不能含其他字母!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void success(float balance){
         QMessageBox ::information(parant, QString("Success"), QString("操作成功!当前余额") + QString::number(balance) + QString("元"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void id_error(){
         QMessageBox :: critical(parant, QString("Error"), QString("卡号或密码错误!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void save_error(){
         QMessageBox :: critical(parant, QString("Error"), QString("保存文件失败!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void repeat_error(){
         QMessageBox :: critical(parant, QString("Error"), QString("卡号重复!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void money_less_error(){
         QMessageBox :: critical(parant, QString("Error"), QString("卡金额过少!请充值!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void logon_error(){
         QMessageBox :: critical(parant, QString("Error"), QString("已上机，无法执行该操作!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void settle_error(){
         QMessageBox :: critical(parant, QString("Error"), QString("已下机，无法再下机!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
    void Input_less_zero(){
        QMessageBox::critical(parant, QString("Error"), QString("金额必须是正值!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    }
    void refund(float balance){
        QMessageBox::information(parant, QString("Success"), QString("退还") + QString::number(balance)  + QString("元成功!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    }
    void admin_error(){
         QMessageBox :: critical(parant, QString("Error"), QString("对不起，密码或账号有误!"), QMessageBox::Ok | QMessageBox::Default,0, 0);
    };
};
#endif // RESULT_H
