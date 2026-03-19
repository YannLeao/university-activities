-- Questão 1
-- Mensagem de boas-vindas personalizada

SELECT '===== Questao 1 =====' AS titulo;
SELECT 'Seja bem-vindo(a) ao programa em SQL!' AS mensagem;

\prompt 'Digite seu nome: ' nome

SELECT 'Ola, ' || :'nome' || '! Seja bem-vindo(a)!' AS mensagem;