//
// Created by Administrator on 2021/4/30.
//

#ifndef SYNTAXPARSER_SYNTAXPARSER_H
#define SYNTAXPARSER_SYNTAXPARSER_H

#include <queue>
#include <stack>
#include <regex>
#include <codecvt>

#include <GrammarResourcePool.h>
#include <AnalyseTableGenerator.h>



class SyntaxParser {

    // �ļ�����
    std::wifstream input;

    std::wofstream output;

    const GrammarResourcePool *pool;

    const AnalyseTableGenerator *atg;

    std::queue<int> tokens_queue;

    std::stack<int> analyse_stack;

    std::stack<int> status_stack;

    std::vector<size_t> lines_index;

    std::wstringstream string_buffer;

    size_t now_line = 1;

    static std::vector<std::wstring> ws_split(const std::wstring& in, const std::wstring& delim);

    static std::pair<std::wstring, std::wstring> get_token_info(const std::wstring &token);

public:

    SyntaxParser(const GrammarResourcePool *pool, const AnalyseTableGenerator *atg):
            input("tokenOut.txt", std::ios::binary),
            pool(pool),
            atg(atg),
            output("SyntaxOut.txt", std::ios::binary){

        auto* codeCvtToUTF8= new std::codecvt_utf8<wchar_t>;
        input.imbue(std::locale(input.getloc(), codeCvtToUTF8));
        output.imbue(std::locale(output.getloc(), codeCvtToUTF8));
    }

    ~SyntaxParser() {
        output.close();
    }

    // �õ����еĲ���ʽ
    void getToken();

    void printSymbol(int symbol_index);

    void printProduction(const Production *p_pdt);

    // �Ե������﷨����
    void parse();

    void printError();

    void printDone();
};


#endif //SYNTAXPARSER_SYNTAXPARSER_H
