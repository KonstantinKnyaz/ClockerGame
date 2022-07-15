#ifndef CLICKERGAME_H
#define CLICKERGAME_H

/*!
 * \brief The ClickerGame class объект с данными игры
 */
class ClickerGame
{

public:
    /*!
     * \brief ClickerGame конструктор
     */
    ClickerGame();
    /*!
     * \brief setSuccessCountClick устанавливает количество правильныз кликов
     * \param click
     */
    void setSuccessCountClick(const int click);
    /*!
     * \brief addSuccessClick добавляет один правильный клик
     */
    void addSuccessClick();
    /*!
     * \brief getSuccessCountClick возвращает количество правильных кликов
     * \return  возвращает целое число правильных кликов
     */
    int getSuccessCountClick();
    /*!
     * \brief setFailedCountClick устанавлавает количество неправильных кликов
     * \param click количество кликов
     */
    void setFailedCountClick(const int click);
    /*!
     * \brief addFailedClick добавляет один неправильный клик
     */
    void addFailedClick();
    /*!
     * \brief getFailedCountClick возвращает количество неправильных кликов
     * \return возвращает целое число
     */
    int getFailedCountClick();
    /*!
     * \brief setOneClick записывает количество кликов за раунд
     */
    void setOneClick();
    /*!
     * \brief getAllClicksAndClear возвращает количество кликов и обнуляет их
     * \return возвращает сделанное количество кликов
     */
    int getAllClicksAndClear();
    /*!
     * \brief allClear обнуляет все счетчики
     */
    void allClear();

private:
    /*!
     * \brief successfulClick хранит количество правильных кликов
     */
    unsigned int successfulClick;
    /*!
     * \brief failedClick хранит количество неправильных кликов
     */
    unsigned int failedClick;
    /*!
     * \brief clicks хранит количество кликов мышкой
     */
    unsigned int clicks;
};

#endif // CLICKERGAME_H
