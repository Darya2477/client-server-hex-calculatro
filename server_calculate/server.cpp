#include "server.h"
Server::Server()
{
    if (this->listen(QHostAddress::Any, 8080))
    {

        qDebug()<<"Server start!";
    }
    else
        qDebug()<<"Server is not start!";
}
Server::~Server()
{
    delete socket;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    if(!sockets_map.keys().contains(socketDescriptor)){
    socket=new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    QObject::connect(socket, &QTcpSocket::readyRead,this, &Server::sendToClient);
    connect(socket, &QTcpSocket::disconnected, this, &Server::deleteLater);
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(er(QAbstractSocket::SocketError)));
    sockets_map.insert(socketDescriptor, socket);
   qDebug()<<"Client connection. Descriptor: "<<socketDescriptor;
    }
}

bool lengthCheck(std::string str){
    if (str.find('.') != std::string::npos) {
       std::string wholePart = str.substr(0, str.find('.'));
       return (wholePart.length() > 24) ? false : true;
    }
    else return (str.length() > 24) ? false : true;
}

QString deleteInsignZeros(std::string str){
    size_t decimalPos = str.find('.');
    if (decimalPos != std::string::npos) {
        size_t lastNonZeroPos = str.find_last_not_of('0');
        if (lastNonZeroPos == decimalPos) {
            str.erase(lastNonZeroPos); // Удалить точку
        } else {
            str.erase(lastNonZeroPos + 1, std::string::npos);
        }
    }
    return QString::fromStdString(str);
}

QString hexToDecimal(QString hexNumber){
    QString integerPart, decimalPart;
    QString decimalNumber="";
    QVector<long long> vec1;
    QVector<long double> vec2;
    int size = hexNumber.size();
    bool isDecimal = false;
    int dotIndex = hexNumber.indexOf('.');
    if (dotIndex != -1) {
        isDecimal = true;
        integerPart = hexNumber.mid(0, dotIndex);
        decimalPart = hexNumber.mid(dotIndex + 1);
        size = integerPart.size() + decimalPart.size();
    } else {
        integerPart = hexNumber;
    }
    if (integerPart.startsWith('-')) {
        integerPart = integerPart.mid(1);
        decimalNumber+="-";
    }
    long long sum1 = 0;
    for (int i = 0; i < integerPart.size(); ++i) {
        char currentChar = integerPart[i].toLatin1();
        int currentValue = 0;

        if (currentChar >= '0' && currentChar <= '9') {
            currentValue = currentChar - '0';
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            currentValue = currentChar - 'A' + 10;
        } else {
            qDebug() << "ERROR!";
            return QString();
        }
        long long weight = pow(16, integerPart.size() - i - 1);
        vec1.append(currentValue * weight);
    }
    for (int i = 0; i < vec1.size(); i++) {
        sum1 += vec1[i];
    }
    decimalNumber += QString::number(sum1);
    if (isDecimal) {
        long double sum2 =0;
        for (int i = 0; i < decimalPart.size(); ++i) {
            char currentChar = decimalPart[i].toLatin1();
            int currentValue = 0;

            if (currentChar >= '0' && currentChar <= '9') {
                currentValue = currentChar - '0';
            } else if (currentChar >= 'A' && currentChar <= 'F') {
                currentValue = currentChar - 'A' + 10;
            } else {
                qDebug() << "ERROR!";
                return QString();
            }

            long double weight = std::pow(16, -(i+1));
            vec2.append(currentValue * weight);
        }
        for (int i = 0; i < vec2.size(); i++) {
            sum2 += vec2[i];
        }
        std::ostringstream oss;
        oss << std::setprecision(12) << sum2;
        decimalNumber += QString::fromStdString(oss.str().erase(0,1));


    }
    return decimalNumber;

}

QString decimalToHex(QString decimalNumber){
     QString hexNumber="";
     QString integerPart;
     QString decimalPart;
     bool isDecimal = false;
     bool isNegative = false;
     int size = decimalNumber.size();
     int dotIndex = decimalNumber.indexOf('.');
     if (dotIndex != -1) {
         isDecimal = true;
         integerPart = decimalNumber.mid(0, dotIndex);
         decimalPart = decimalNumber.mid(dotIndex + 1);
         decimalPart.prepend("0.");
         size = integerPart.size() + decimalPart.size();
     } else {
         integerPart = decimalNumber;
     }
     if (integerPart.startsWith('-')) {
         integerPart = integerPart.mid(1);
         isNegative=true;
     }
  QString str1="";

  long long intPart = integerPart.toLongLong();
    if (intPart>0){
        while (intPart > 0) {
            int remainder = intPart % 16;

            if (remainder < 10) {
                hexNumber.prepend(QString::number(remainder));
            } else {
                hexNumber.prepend(QChar('A' + remainder - 10));
            }

            intPart /= 16;
        }
    }
    else{
        hexNumber.prepend("0");
    }


   if (isNegative) {
      hexNumber.prepend("-");
   }

   long double decPart;
   std::istringstream iss(decimalPart.toStdString());
   iss>>decPart;

   if (decPart>0){
       hexNumber += '.';
       const int maxFractionalDigits = 8;
       int i=0;

       long long digit;
       while (decPart>0 && i<maxFractionalDigits){
           std::ostringstream oss, oss_1;
           decPart = decPart*16;
           oss_1 << std::fixed << std::setprecision(12) << decPart;
           digit = QString::fromStdString(oss_1.str().substr(0, oss_1.str().find("."))).toLongLong();
           if (digit < 10)
           {
             hexNumber += QString::number(digit);
           }
           else
           {
             hexNumber += QChar('A' + static_cast<char>(digit) - 10);
           }
           decPart = decPart - digit;
           ++i;
       }
   }
     return hexNumber;
}


QString probel(QString s)
{
  while (s[0]==' ')
      s.remove(0,1);
  return s;
}
long long fact(int digit)
{
    if (std::floor(digit) == digit){
        return (digit==2 || digit== 1)?digit:digit*fact(digit-1);
    }
    else return -1;
}

QString Server::id(QString st,QSet <char> operators)
{
    st=probel(st);
    bool key = true;
    QRegExp regular("^√?s?c?l?!?[A-F\\d]*\\.?[A-F\\d]+(e[A-F\\d]+)?$");
    QString id="";
    int i=0;
        while (i < st.length())
        {
            if (operators.contains((st[i]).toLatin1()) || st[i]==' ')
            {
                if (id.contains(regular)){
                    return id;
                }
                else{
                    QString str="Error digit " + id;
                    socket->write(str.toStdString().c_str());
                    return "E";
                }
            }
            else {
                if (!(st[i]=='(')){
                id+=st[i];
            }
        }
            i++;
        }
        if (id.contains(regular)){
            return id;
        }
        else
            return "Error digit " + id;
}

QVector <QString> Server::scaner(QString stroka, QChar mode)
{
  stroka.push_back(')');
  stroka=probel(stroka);
  stroka=stroka.replace("lg", "l");
  stroka=stroka.replace("sin", "s");
  stroka=stroka.replace("cos","c");
  QString word="";
  QVector<QString> mas;
  mas.append("(");
  QSet <char> conteiner={'+', '-', '*', '/', ')', '^'};
  while (!stroka.isEmpty())
  {
      if (((!conteiner.contains(stroka[0].toLatin1()) && stroka[0]!='(')||(stroka[0]=='-' && mas.constLast()=="(")) &&!(stroka[0]=='!' && stroka[1]=='(') && !(stroka[0]=='l' && stroka[1]=='(') && !(stroka[0]=='s' && stroka[1]=='(') && !(stroka[0]=='c' && stroka[1]=='(') && !(stroka[0]==8730 && stroka[1]=='('))
      {
        bool key=false;
        if (mas.constLast()=="(")
        {
            stroka=probel(stroka);
            if(stroka[0]=='-')
            {
            stroka.remove(0,1);
            key=true;
            }
        }
        word=id(stroka, {'+', '-', '*', '/',' ', ')', '^'});
        int length=word.length();
        if (word[0]=='e')
            return {};
        if (word[0]=='!'){
            word.remove(0,1);
            if (word[0]=='-')
            {
                QString str="Error digit "+ word;
                socket->write(str.toStdString().c_str());
                return {};
            }
            QString word_prev = word;
            if (mode=='2'){
                word = hexToDecimal(word);
            }
            if (round(word.toDouble())!=word.toDouble())
            {
                QString str="Fact can't have double value:"+ word_prev;
                socket->write(str.toStdString().c_str());
                return {};
            }
            if (round(word.toDouble())>=24)
            {
                QString str="Length of int part more than 24";
                socket->write(str.toStdString().c_str());
                return {};
            }
            word=QString::number(fact(word.toInt()));

        }
        if (word[0]=='l'){
            word.remove(0,1);
            if (word[0]=='-')
            {
                QString str="Error digit lg"+ word;
                socket->write(str.toStdString().c_str());
                return {};
            }
            QString word_prev = word;
            if (mode=='2'){
                word = hexToDecimal(word);
            }
            word=QString::number(log10(word.toDouble()));
        }
        if (word[0]==8730){
            word.remove(0,1);
            if (word[0]=='-')
            {
                QString str="Error digit √"+ word;
                socket->write(str.toStdString().c_str());
                return {};
            }
            if (mode=='2'){
                word = hexToDecimal(word);
            }
            word=QString::number(sqrt(word.toDouble()));
        }
        if (word[0]=='s'){
            word.remove(0,1);
            if (mode=='2'){
                word = hexToDecimal(word);
            }
            word=QString::number(qSin(word.toDouble()));
        }
        if (word[0]=='c'){
            word.remove(0,1);
            if (mode=='2'){
                word = hexToDecimal(word);
            }
            word=QString::number(qCos(word.toDouble()));
        }
        if (key){
        word.push_front('-');
        if(stroka[length-1]==')')
        {
            mas.removeLast();
           stroka.remove(0, length+1);
        }
        else
            stroka.remove(0,length);
        }
        else
        stroka.remove(0, length);
        mas.append(word);
        probel(stroka);
      }
      else
      {
          mas.append((QString)stroka[0]);
          stroka.remove(0, 1);
      }
  }
  qDebug()<<"True";
  qDebug()<<stroka;
  return mas;
}

QString Server::parser(QString str){
    QChar mode = str[str.length()-1];
    QString reg_exp, reg_item;
    if (mode=='1'){
        reg_exp = "^-?\\d*\\.?\\d+(e\\d+)?$";
        reg_item ="^(-?\\d*.?\\d+|\\d*.?\\d+e\\d+|\\d*.?\\d+e[+-]0?\\d+)$";
    }
    else if (mode=='2'){
        reg_exp = "^-?[A-F\\d]*\\.?[A-F\\d]+(e[A-F\\d]+)?$";
        reg_item = "^(-?[A-F\\d]*.?[A-F\\d]+|[A-F\\d]*.?[A-F\\d]+e[A-F\\d]+|[A-F\\d]*.?[A-F\\d]+e[+-]0?[A-F\\d]+)$";
    }
    str = str.remove(str.length()-1,1);
    if (str.contains(QRegExp(reg_exp)))
        return str;
    QVector<QString> tokens;
    str=probel(str);
    tokens=scaner(str,  mode);
    if (tokens.isEmpty())
        return "";
    QMap <int, int> index_map;//first index-index of str, second index-number of str[i]
    QSet <char> cont={'+', '-', '*', '/', '^'};
    str.push_back(')');
    str.push_front('(');
    QVector<QString> digits;
    for (auto item: tokens)
    {
        if (item.contains(QRegExp(reg_exp)))
            digits.push_back(item);
    }
    while (!tokens.isEmpty()){
        int number=-1;
        index_map.clear();
        for (int i=0;i<tokens.length();i++)
        {
            if (tokens[i].contains(QRegExp(reg_item))||tokens[i]=="(")
                number++;
            if (tokens[i]==")")
                number--;
            if (tokens[i].length()==1)
            if (cont.contains(tokens[i].toStdString().c_str()[0]))
            {
                number--;
                index_map[i]=number;
            }
        }
        if (index_map.size()>=digits.size())
            return "not enough digits";
        if (index_map.size()<digits.size()-1)
            return "not enough operators";
        if (number<0)
            return "To much )";
        if (number>0)
            return "To much (";
        QList <int> list=index_map.values();
        std::sort(list.rbegin(), list.rend());
        if (!list.isEmpty()){
        int max=list[0];
        QList <int> mas=index_map.keys(max);
        bool key=false;
        int first_operator_index=mas[0];
        for (auto index: mas)
        {
            if (tokens[index]=="^")
            {
                key = true;
                if (tokens[index-1].contains(QRegExp(reg_item)) && tokens[index+1].contains(QRegExp(reg_item)))
                {
                   long double token1, token2;
                   if (mode=='1'){
                   std::istringstream iss_1(tokens[first_operator_index-1].toStdString());
                   std::istringstream iss_2(tokens[first_operator_index+1].toStdString());
                   iss_1>>token1;
                   iss_2>>token2;
                }
                 else if (mode=='2'){
                   std::istringstream iss_1(hexToDecimal(tokens[first_operator_index-1]).toStdString());
                   std::istringstream iss_2(hexToDecimal(tokens[first_operator_index+1]).toStdString());
                   iss_1>>token1;
                   iss_2>>token2;
                 }
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(12) << qPow(token1, token2);
                if ((!lengthCheck(oss.str())) || (oss.str()=="inf")){
                    QString str="Length of int part more than 24";
                    socket->write(str.toStdString().c_str());
                    return "";
                }
                tokens[index]=QString::fromStdString(oss.str());
                tokens.remove(--index);
                tokens.remove(index+1);
                first_operator_index=index;
                digits.remove(0,1);
                break;
                }
            }

        }
        for (auto index: mas)
        {
            if(tokens[index]=="*")
            {
             key = true;
             if (tokens[index-1].contains(QRegExp(reg_item)) && tokens[index+1].contains(QRegExp(reg_item)))
             {
               long double token1, token2;
               if (mode=='1'){
                   std::istringstream iss_1(tokens[first_operator_index-1].toStdString());
                   std::istringstream iss_2(tokens[first_operator_index+1].toStdString());
                   iss_1>>token1;
                   iss_2>>token2;
               }
               else if (mode=='2'){
                   std::istringstream iss_1(hexToDecimal(tokens[first_operator_index-1]).toStdString());
                   std::istringstream iss_2(hexToDecimal(tokens[first_operator_index+1]).toStdString());
                   iss_1>>token1;
                   iss_2>>token2;
               }
               std::ostringstream oss;
               oss <<std::fixed<< std::setprecision(12) << token1*token2;
               if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                   QString str="Length of int part more than 24";
                   socket->write(str.toStdString().c_str());
                   return "";
               }
               if ((!lengthCheck(oss.str()))||(oss.str()=="inf")) return "";
               tokens[index]=QString::fromStdString(oss.str());
               tokens.remove(--index);
               tokens.remove(index+1);
               first_operator_index=index;
               digits.remove(0,1);
               break;
             }
            }
            if(tokens[index]=="/")
            {
                key = true;
                if (tokens[index-1].contains(QRegExp(reg_item)) && tokens[index+1].contains(QRegExp(reg_item)))
                {
                  long double token1, token2;
                  if (mode=='1'){
                      std::istringstream iss_1(tokens[first_operator_index-1].toStdString());
                      std::istringstream iss_2(tokens[first_operator_index+1].toStdString());
                      iss_1>>token1;
                      iss_2>>token2;
                  }
                  else if (mode=='2'){
                      std::istringstream iss_1(hexToDecimal(tokens[first_operator_index-1]).toStdString());
                      std::istringstream iss_2(hexToDecimal(tokens[first_operator_index+1]).toStdString());
                      iss_1>>token1;
                      iss_2>>token2;
                  }
                  if (token2==0){
                      QString str="ERROR: Zero Division";
                      socket->write(str.toStdString().c_str());
                      return "";
                  }
                  std::ostringstream oss;
                  oss <<std::fixed<< std::setprecision(12) << token1/token2;
                  if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                      QString str="Length of int part more than 24";
                      socket->write(str.toStdString().c_str());
                      return "";
                  }
                  tokens[index]=QString::fromStdString(oss.str());
                  tokens.remove(--index);
                  tokens.remove(index+1);
                  first_operator_index=index;
                  digits.remove(0,1);
                  break;
                }
            }
        }
        if (!key)
        {
            if (tokens[first_operator_index-1].contains(QRegExp(reg_item)) && tokens[first_operator_index+1].contains(QRegExp(reg_item)))
            {
            if (tokens[first_operator_index]=="+")
              {
               long double token1, token2;
               if (mode=='1'){
                   std::istringstream iss_1(tokens[first_operator_index-1].toStdString());
                   std::istringstream iss_2(tokens[first_operator_index+1].toStdString());
                   iss_1>>token1;
                   iss_2>>token2;
               }
               else if (mode=='2')
               {
                   std::istringstream iss_1(hexToDecimal(tokens[first_operator_index-1]).toStdString());
                   std::istringstream iss_2(hexToDecimal(tokens[first_operator_index+1]).toStdString());
                   iss_1>>token1;
                   iss_2>>token2;
               }
               std::ostringstream oss;
               oss <<std::fixed<< std::setprecision(12) << token1+token2;
               if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                   QString str="Length of int part more than 24";
                   socket->write(str.toStdString().c_str());
                   return "";
               }
               tokens[first_operator_index]=QString::fromStdString(oss.str());
               tokens.remove(--first_operator_index);
               tokens.remove(first_operator_index+1);
               digits.remove(0,1);
            }
            if (tokens[first_operator_index]=="-")
            {
                long double token1, token2;
                if (mode=='1')
                {
                    std::istringstream iss_1(tokens[first_operator_index-1].toStdString());
                    std::istringstream iss_2(tokens[first_operator_index+1].toStdString());
                    iss_1>>token1;
                    iss_2>>token2;
                }
                else if (mode=='2')
                {
                    std::istringstream iss_1(hexToDecimal(tokens[first_operator_index-1]).toStdString());
                    std::istringstream iss_2(hexToDecimal(tokens[first_operator_index+1]).toStdString());
                    iss_1>>token1;
                    iss_2>>token2;
                }
                std::ostringstream oss;
                oss <<std::fixed<< std::setprecision(12) << token1-token2;
                if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                    QString str="Length of int part more than 24";
                    socket->write(str.toStdString().c_str());
                    return "";
                }
                tokens[first_operator_index]=QString::fromStdString(oss.str());
                tokens.remove(--first_operator_index);
                tokens.remove(first_operator_index+1);
                digits.remove(0,1);
            }
            }
        }
        if (tokens[first_operator_index+1]==")" && tokens[first_operator_index-1]=="(")
        {
            tokens.remove(first_operator_index+1);
            tokens.remove(--first_operator_index);
            if (tokens.length()==1){
                if (mode=='1') return deleteInsignZeros(tokens[0].toStdString());
                else if (mode=='2') return deleteInsignZeros(decimalToHex(tokens[0]).toStdString());
            }
        }
        int i=0;
        }
        int i=0;
        while (i<tokens.length()-1)
        {
           if(tokens[i].contains(QRegExp(reg_item)))
           {
               long double token;
               if (mode=='1')
               {
                std::istringstream iss(tokens[i].toStdString());
                iss>>token;
               }
               else if (mode=='2')
               {
                std::istringstream iss(hexToDecimal(tokens[i]).toStdString());
                iss>>token;
               }
               std::ostringstream oss;
               if (tokens[i-1]=="!")
                {
                    oss <<std::fixed<< std::setprecision(12) << fact(token);
                    tokens[i]=QString::fromStdString(oss.str());
                    tokens.remove(i-1);
                    i--;
                }
                if (tokens[i-1]=="l")
                {
                    oss <<std::fixed<< std::setprecision(12) << log10(token);
                    if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                        QString str="Length of int part more than 24";
                        socket->write(str.toStdString().c_str());
                        return "";
                    }
                    tokens[i]=QString::fromStdString(oss.str());
                    tokens.remove(i-1);
                    i--;
                }
                if (tokens[i-1]=="s")
                {
                    oss <<std::fixed<< std::setprecision(12) << qSin(token);
                    if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                        QString str="Length of int part more than 24";
                        socket->write(str.toStdString().c_str());
                        return "";
                    }
                    tokens[i]=QString::fromStdString(oss.str());
                    tokens.remove(i-1);
                    i--;
                }
                if (tokens[i-1]=="c")
                {
                    oss <<std::fixed<< std::setprecision(12) << qCos(token);
                    if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                        QString str="Length of int part more than 24";
                        socket->write(str.toStdString().c_str());
                        return "";
                    }
                    tokens[i]=QString::fromStdString(oss.str());
                    tokens.remove(i-1);
                    i--;
                }
                if (tokens[i-1]=="√")
                {

                    oss <<std::fixed<< std::setprecision(12) << sqrt(token);
                    if ((!lengthCheck(oss.str()))||(oss.str()=="inf")){
                        QString str="Length of int part more than 24";
                        socket->write(str.toStdString().c_str());
                        return "";
                    }
                    tokens[i]=QString::fromStdString(oss.str());
                    tokens.remove(i-1);
                    i--;
                }
                if (tokens[i-1]=="(" && tokens[i+1]==")")
                {
                    tokens.remove(i+1);
                    tokens.remove(--i);
                    i--;
                    if(tokens.length()==1)
                    {
                        if (mode=='1') return deleteInsignZeros(tokens[0].toStdString());
                        else if (mode=='2') return  deleteInsignZeros(decimalToHex(tokens[0]).toStdString());
                    }
                }
           }
           i++;
        }
    }
        return "Uncorrect str";
}

void Server::sendToClient()
{

    QTcpSocket *s=(QTcpSocket*)sender();
    bool key=false;
    for (auto it=sockets_map.begin();it!=sockets_map.end();it++)
    {
        if (it.value()==s){
            key=true;
        }
    }
    if(!key)
        return;
   QByteArray data=s->readAll();
      QString str=QString(data);
      qDebug()<<"Read...\n";

      s->write(parser(str).toStdString().c_str());
}
void Server::deleteLater()
{
    QTcpSocket *delete_socket=qobject_cast<QTcpSocket *>(sender());
    for (auto it=sockets_map.begin();it!=sockets_map.end();it++)
    {
        if (it.value()==delete_socket){
            sockets_map.remove(it.key());
        }
    }
    qDebug()<<"Delete";
    delete_socket->deleteLater();
}
