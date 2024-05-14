file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h
add_executable(${SKIPLIST} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${vector}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
