-- Questão 5
--  Análise de um array

SELECT '===== Questao 5 =====' AS titulo;

\prompt 'Digite o primeiro numero : ' n1
\prompt 'Digite o segundo numero  : ' n2
\prompt 'Digite o terceiro numero : ' n3
\prompt 'Digite o quarto numero   : ' n4
\prompt 'Digite o quinto numero   : ' n5

WITH 
    numeros(val) AS (
        VALUES
        (:'n1'::int),
        (:'n2'::int),
        (:'n3'::int),
        (:'n4'::int),
        (:'n5'::int)
    )

SELECT
    MAX(val) AS maior,
    MIN(val) AS menor,
    AVG(val)::NUMERIC(10,2) AS media,
    PERCENTILE_CONT(0.5) WITHIN GROUP (ORDER BY val) AS mediana
FROM numeros;