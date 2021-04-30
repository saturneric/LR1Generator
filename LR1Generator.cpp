#include <iostream>
#include <ctime>

#include <SymbolTable.h>
#include <GrammarResourcePool.h>

#include <AnalyseTableGenerator.h>

using std::vector;
using std::wstring;

using std::wcout;
using std::endl;


#include <LR1Generator.h>
#include <SyntaxParser.h>


int main() {
    clock_t start,end;//����clock_t����
    start = clock(); //��ʼʱ��

    const GrammarResourcePool *pool;

    const AnalyseTableGenerator *atg;


    LR1Generator generator;

    generator.getProductions();

    generator.run();

    generator.output(pool, atg);

    //���ʱ��
    end = clock();   //����ʱ��
    double times = double(end-start)/CLOCKS_PER_SEC;
    wcout<<"LR1Generator Run time = "<< times <<"s MicroSeconds" << " = " << times * 1000 <<"ms" << endl;

    start = clock(); //��ʼʱ��

    SyntaxParser syntaxParser(pool, atg);

    syntaxParser.getToken();

    syntaxParser.parse();

    //���ʱ��
    end = clock();   //����ʱ��
    times = double(end-start)/CLOCKS_PER_SEC;
    wcout<<"SyntaxParser Run time = "<<times<<"s MicroSeconds " << " = " << times * 1000 <<"ms" << endl;

    return 0;
}

