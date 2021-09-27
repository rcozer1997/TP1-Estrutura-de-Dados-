# Primeiro Trabalho Prático de Estrutura de Dados I
** Rafael de O. Cozer e Artur Mendes de Moraes
DI/UFES**

# Introdução
> O projeto visa simular a interface básica de um serviço de streaming de música, implementando o conceito de listas simplesmente encadeadas. O código foi elaborado utilizando-se diversas TAD's, atribuindo cada funcionalidade do sistema à uma biblioteca específica. A intenção final do projeto, era criar playlists para cada usuário, separadas pelas bandas fornecidas, bem como suas respectivas músicas. Além de, também, criar uma rede de amizades, onde poder-se-ia comparar os gostos musicais entre os amigos.

> Nos tópicos a seguir, um pouco de cada uma dessas funcionalidades implementadas, seguindo a linha de raciocínio utilizada.

# 1. listaU e usuarios.h
Nessas TAD’s foram implementados os trechos de códigos relacionados diretamente ao tratamento dos usuários. Na listaU, foi trabalhada a lista de usuários e na usuários.h é onde começamos a rodar o código, através da inicializaPlayED.

# 2. listaP e playlists.h
Aqui, foram trabalhados os trechos relacionados à criação inicial das playlists. Novamente, assim como anteriormente, a listaP foi onde criou-se as listas de playlists, atribuídas aos usuários, e na playlists.h trabalhamos as questões das playlists em si.

# 3. listaM e musicas.h
Nessas bibliotecas, foram trabalhadas as músicas dos arquivos txt, à fim decriar a playlist refatorada e armazenar os nomes das músicas, bem como suas respectivas bandas, para posteriormente serem criadas as pastas de cada usuário, com suas respectivas playlists. Novamente, com a divisão entre um TAD para trabalhar o conceito de listas e um TAD para trabalhar os códigos das músicas em si.

# 4. listaA e amizades.h
Por fim, aqui trabalhou-se a questão das amizades entre os usuários, à fim de analisar essa rede de amizades e gerar um arquivo “similaridades.txt”, com a quantia de similaridades de gosto musical entre os amigos, dentro de suas respectivas amizades. E, claro, houve a separação entre um TAD onde criouse essa lista de amizades e um TAD, amizades.h, onde trabalhou-se as amizades em si.

# Arquivos
É importante ressaltar aqui da importância da localização dos arquivos de entrada, que devem estar localizadas dentro da pasta “data” para que o código funcione de forma apropriada. Como arquivos de entradas, utilizou-se os arquivos de playlists txt fornecidos pela professora, bem como o arquivo de amizades.txt. Como arquivos de saída, como esperado, gerou-se os arquivos “similaridades.txt” e os arquivos “played_refatorada.txt”, bem como as pastas separadas por usuários, com suas respectivas playlists, separadas por nome das bandas/cantores.

# Conclusão
O trabalho permitiu trabalhar bem o conceito de listas simplesmente encadeadas, uma vez que todo o projeto girou em torno dessa ideia. Além disso, exigiu que se trabalhasse no quesito organização, uma vez que foram utilizadas uma grande quantidade de TAD’s para este projeto. Foi um trabalho desafiador e, no entanto, simples. Dessa forma, pôde-se
aprimorar e fixar bem os conceitos vistos, de tal maneira à contribuir para evolução dos alunos enquanto cientistas da computação. Como maiores dificuldades vistas, pôde-se apresentar principais:

Dificuldade relacionada aos #includes:
Em alguns momentos, principalmente no inicio do projeto, foram observados alguns problemas em relação ao uso dos #includes, para atribuir uma TAD à outra. Em certos momentos, isso estava causando loops de includes e, em outros momentos, o código simplesmente não aceitava o include da forma como estava sendo implementado.

Dificuldade com a liberação da memória:
Houve uma certa dificuldade na hora de liberar a memória alocada, uma vez que se optou por implementar os “free’s” ao final, não durante a implementação do código. Sendo assim, teve-se que analisar com cuidado a forma como o código estava sendo executado, para que as liberações de memórias fossem encaixadas nos locais certos. Isso acabou consumindo um certo tempo e, talvez, a decisão de liberar a memória apenas no final não tenha sido tão interessante.

# Bibliografia
https://pt.stackoverflow.com/
https://devdoc.net/
https://cboard.cprogramming.com/
https://www.geeksforgeeks.org/
