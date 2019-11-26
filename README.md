# projeto-itp

Esse é um projeto desenvolvido para a matéria de Introdução a Técnicas de Programação, pelas alunas Mariane Felix e Maria Eduarda.

Na solução, foram implementadas as seguintes funcionalidades:
1. criar imagem;
2. limpar imagem;
3. definir cor atual;
4. definir ponto;
5. desenhar reta;
6. desenhar círculo;
7. desenhar retângulo;
8. desenhar polígonos;
9. desenhar polígonos 3d;
10. desenhar curvas;
11. definir espessura do pincel;
12. preencher figuras;
13. salvar imagem.

Para rodar esse programa algumas coisas são necessárias:
1. ter o gcc instalado em seu computador;
2. abra o terminal/cmd;
3. entre na pasta do projeto
3. digite o comando make (ele irá executar todas as dependências necessárias para o programa);
4. digite o comando ./main;
Dessa forma, a imagem terá sido gerada na pasta do projeto.

No desenvolvimento do projeto, as funcionalidades de cada etapa foram divididas para cada uma da dupla da seguinte maneira:

1. Tipos de dados necessários e modularização do programa - Mariane;
2. Leitura do arquivo de especificação e geração da imagem ppm - Maria Eduarda;
3. Definição de ponto e cor atual - Mariane;
4. Desenho de retas - Maria Eduarda;
5. Desenho de retângulo e polígonos - Mariane;
6. Desenho de círculo - Maria Eduarda;
7. Preenchimento de figuras - Mariane;

Além das funções acima, foram desenvolvidas algumas extras:

1. Desenhar polígonos 3d - Maria Eduarda
No arquivo de especificação, o comando dessa primitiva é polygon3D e deve ser seguido da profundidade da figura 3d, da quantidade de pontos e dos pontos que deseja, como no exemplo abaixo.
ex.: polygon3D 100 4 800 800 1000 800 1000 600 800 600

2. Difinir tamanho do pincel - Maria Eduarda
No arquivo de especificação, antes de cada comando de desenho, deve ser especificado o tamanho do pincel com o comando spencil, como mostra o exemplo.
ex.: spencil 40

3. Desenhar curvas - Maria Eduarda
O comando para essa primitiva é curve e é seguida da quantidade de pontos e os pontos para desenhar a curva.
ex.: curve 3 500 500 800 800 1500 500 
