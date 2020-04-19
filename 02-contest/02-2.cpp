namespace numbers{
    class complex_stack{
            private:
                complex *begin = nullptr;
                size_t stack_size = 0;
            public:
                complex_stack(){}

                complex_stack(size_t size){
                    begin = (complex*) (operator new[] (sizeof(complex) * size));
                    stack_size = size;
                }

                complex_stack &operator= (const complex_stack &stack){
                    if(begin != stack.begin){
                        delete[] begin;
                        begin = (complex*) (operator new[] (sizeof(complex) * stack.size()));
                        stack_size = stack.size();

                        for(size_t i = 0; i < stack.size(); i++){
                            begin[i] = stack[i];
                        }
                    }
                    return *this;
                }

                complex_stack(complex_stack &stack){
                    begin = (complex*) (operator new[] (sizeof(complex) * stack.size()));
                    stack_size = stack.size();
                    for(size_t i = 0; i < stack.size(); i++){
                        begin[i] = stack[i];
                    }
                }

                complex_stack(complex_stack &&stack){
                    if(begin != stack.begin){
                        delete[] begin;
                        begin = (complex*) (operator new[] (sizeof(complex) * stack.size()));
                        stack_size = stack.size();

                        for(size_t i = 0; i < stack.size(); i++){
                            begin[i] = stack[i];
                        }
                        stack.begin = nullptr;
                        stack.stack_size = 0;
                    }
                }

                complex_stack &operator= (complex_stack &&stack){
                    if(begin != stack.begin){
                        delete[] begin;
                        begin = stack.begin;
                        stack_size = stack.size();

                        for(size_t i = 0; i < stack.size(); i++){
                            begin[i] = stack[i];
                        }
                        
                        stack.begin = nullptr;
                        stack.stack_size = 0;
                    }
                    return *this;
                }

                size_t size() const {
                    return stack_size;
                }

                ~complex_stack() {
                    delete[] begin;
                }

                complex &operator[] (int i) const {
                    return begin[i];    
                }

                complex operator+ (void) const {
                    return begin[stack_size - 1];
                }

                complex_stack friend operator<< (const complex_stack &stack, const complex &num){
                    complex_stack new_stack(stack.size() + 1);
                    for(size_t i = 0; i < stack.size(); i++){
                        new_stack[i] = stack[i];
                    }
                    new_stack[stack.size()] = num;
                    return new_stack;
                }

                complex_stack friend operator~ (const complex_stack &stack){
                    complex_stack new_stack(stack.size() - 1);

                    for(size_t i = 0; i < stack.size() - 1; i++){
                        new_stack[i] = stack[i];
                    }
                    return new_stack;
                }
        };
}
