#include <iostream>
#include <ctime>

#include <Automata.h>

#include <SymbolTable.h>
#include <GrammarResourcePool.h>
#include <AnalyseTableGenerator.h>

#include <LR1Generator.h>
#include <SyntaxParser.h>

using std::vector;
using std::wstring;

using std::wcout;
using std::endl;


int main(int argc, const char* argv[]) {

    try {

        wcout << "Compile Program Based on LR(1) Written By Saturneric(���� 2018303206)" << endl;

        wcout << "��ʦע�⣺���������ֹؼ��ֵĴ�Сд������" << endl
        << "��������ԭ���Ǳ�����ʵ���ϻ�û�м������������Բ����ֹؼ��ִ�Сд��" << endl;

        if (argc < 2) {
            printf("Usage: <Input Path>\n");
            return -1;
        }

        clock_t start, end;
        start = clock();

        Automata atm(argv[1]);

        atm.parse();

        atm.output();

        // ���ʱ��
        end = clock();
        double times = double(end - start) / CLOCKS_PER_SEC;
        wcout << "Token Automata Run time = " << times << "s MicroSeconds" << " = " << times * 1000 << "ms" << endl;

        // LR1����
        start = clock();

        const GrammarResourcePool *pool;

        const AnalyseTableGenerator *atg;


        LR1Generator generator;

        generator.getProductions();

        generator.run();

        generator.output(pool, atg);

        //���ʱ��
        end = clock();   //����ʱ��
        times = double(end - start) / CLOCKS_PER_SEC;
        wcout << "LR(1) Generator Run time = " << times << "s MicroSeconds" << " = " << times * 1000 << "ms" << endl;


        // �﷨����
        start = clock(); //��ʼʱ��

        SyntaxParser syntaxParser(pool, atg);

        syntaxParser.getToken();

        syntaxParser.parse();

        //���ʱ��
        end = clock();   //����ʱ��
        times = double(end - start) / CLOCKS_PER_SEC;
        wcout << "Syntax Parser Run time = " << times << "s MicroSeconds " << " = " << times * 1000 << "ms" << endl;

    } catch(std::runtime_error &e) {
        std::wcout << "Runtime Error: " << e.what() << endl;
    }

    return 0;
}

