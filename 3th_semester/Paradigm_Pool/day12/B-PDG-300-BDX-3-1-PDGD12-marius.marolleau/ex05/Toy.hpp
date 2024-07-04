/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include <string>


class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            WOODY,
            BUZZ,
        };
        Toy();
        Toy(ToyType type, std::string name, std::string filename);
        ~Toy();
        Toy(const Toy &);
        Toy &operator=(const Toy &t);
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string name);
        bool setAscii(std::string filename);
        virtual void speak(std::string statement);
        virtual bool speak_es(std::string statement);
        Toy &operator<<(std::string to_replace);
        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK,
                };
                const char *what() const;
                const char *where() const;
                ErrorType type;
        };
        Error getLastError();
    protected:
    private:
        ToyType _type;
        Error error;
        std::string _name;
        std::string _picture;
};

std::ostream const &operator<<(std::ostream &s, const Toy &t);


#endif /* !TOY_HPP_ */
