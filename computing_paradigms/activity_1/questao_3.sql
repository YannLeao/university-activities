-- Questão 3
--  Tipo do número

SELECT '===== Questao 3 =====' AS titulo;

\prompt 'Digite um numero inteiro: ' num


SELECT 
    :'num'::int AS numero,
    CASE
        WHEN :'num'::int > 0 THEN 'Positivo'
        WHEN :'num'::int < 0 THEN 'Negativo'
        ELSE 'Zero'
    END AS classificacao,
    CASE
        WHEN MOD(:'num'::int, 2) = 0 THEN 'Par'
        ELSE 'Impar'
    END AS paridade;