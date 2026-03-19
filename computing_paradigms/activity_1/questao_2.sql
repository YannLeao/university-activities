-- Questão 2
-- Operações matemáticas

SELECT '===== Questao 2 =====' AS titulo;

\prompt 'Digite o primeiro numero: ' num1
\prompt 'Digite o segundo numero: ' num2

SELECT 
    :'num1'::INT AS numero_1,
    :'num2'::INT AS numero_2,
    (:'num1'::INT + :'num2'::INT) AS soma,
    (:'num1'::INT - :'num2'::INT) AS subtracao,
    (:'num1'::INT * :'num2'::INT) AS multiplicacao,
    ROUND(
        :'num1'::NUMERIC / NULLIF(:'num2'::NUMERIC, 0),
        2
    ) AS divisao;