


namespace Utils
{
    template<typename T>
    int id_generator()
    {
        static int id = 0;
        return ++id;
    }
}

