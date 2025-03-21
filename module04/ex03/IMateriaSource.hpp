#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

class IMateriaSource {
   public:
    IMateriaSource();
    IMateriaSource(const std::string);
    IMateriaSource(const IMaterialSource& other);
    IMateriaSource& operator=(const IMateriaSource& other);
    virtual ~IMateriaSource() = 0;

    /*-------------------- Public member functions --------------------*/
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif