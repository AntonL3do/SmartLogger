# SmartLogger

SmartLogger es una aplicación que permite generar estadísticas sobre las pulsaciones del teclado.
Sus modos de operación son:
- Modo Live -> Se activa automáticamente el detector de pulsaciones y, posteriormente, genera un estadístico sobre los datos registrados tras presionar [ESC]. En este modo las estadísticas no serán guardadas y solo podrán ser visibles en ese momento.
- Modo Live con registro -> Similiar al Modo Live, genera un archivo al finalizar el registro de pulsaciones. El archivo se identifica con la fecha y hora de creación.
- Modo persistente -> El más completo de todos, si es la primera vez que se ejecuta, generará un archivo de registro y las próximas veces que se ejecute, actualizará sus valores con las nuevas pulsaciones. Al guardar un registro actualizable, permite generar estadísticas más completas. Dentro de este modo se podrá iniciar o continuar con el registro, y consultar las estadísticas acumuladas del archivo 'log_DB.txt'.

Todos los registros se guardarán en el mismo directorio donde se encuentre el programa, y de la misma forma, solo podrán ser leídos si se encuentran en el directorio del programa.

(!)AVISO: En ningún caso modifique el archivo de registro 'log_DB.txt', de lo contrario causará un error en el programa. Si desea eliminar el registro acumulado simplemente elimine el archivo o cambie su nombre.

Sistema operativo: Mínimo Windows 2000 Professional.
