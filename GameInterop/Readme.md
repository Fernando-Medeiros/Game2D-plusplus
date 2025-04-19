# Exemplo de biblioteca de exportação

Nota para não esquecer:
1 - Compilar este projeto;
2 - Adicionar GameCore.dll e GameInterop.dll na pasta include ou libs do projeto C#;
3 - Incluir na compilação estas dlls para serem jogadas na pasta de output (ou jogar na pasta onde tem o .exe);

?? - As duas dlls precisam estar juntas na pasta.
?? - Exportar apenas tipos simples C porque a exportação não funciona com tipos C++ e complexos;