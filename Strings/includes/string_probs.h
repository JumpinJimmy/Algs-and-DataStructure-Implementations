#ifndef STRING_PROBS_H
#define STRING_PROBS_H
#include <iostream>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
class StringProblem{

    public:
        StringProblem();
        // StringProblem(const StringProblem &rhs);
        virtual ~StringProblem();
        // const StringProblem & operator=(const StringProblem & rhs);
        void RemoveChars(std::string &source_str, std::string &remove_chars);
        void RemoveChars(const char source_str[], const char remove_chars[]);
        // bool IsAdjacentTo(StringProblem& v);
        // std::vector< Edge* > Edges();
        // int Degree(); //Aggregate # of Incident edges (ignores directed)
        // virtual int Key();
        // void SetKey(int new_key);
        // const std::string& GetValue() const;
        // const std::string* Value() const;
        // bool AddIncidentEdge(Edge* e);
        // bool RemoveIncidentEdge(Edge* e);
        // bool IsAdjacentTo(int vertex_id);
        // virtual void PrintNodeData();
    private:
        void clear_sstream();
        // operator*();
        // int key_;
        // std::string value_;
        // std::vector< Edge* > IncidentEdges_;
        std::stringstream ss_; //(std::ios_base::out | std::ios_base::ate);
};
#endif // STRING_PROBS_H
