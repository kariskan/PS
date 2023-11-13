SELECT ANIMAL_TYPE, 
case 
    when NAME is null then 'No name'
    else NAME
end AS NAME,
SEX_UPON_INTAKE
from animal_ins
order by animal_id