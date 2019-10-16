# Otonom-Park
Mobil Kontrollü Otonom Park Eden Araç Projemde Android ve Arduino kullandım. Projemin algoritması şu şekildedir: 
Paralel Park Durumu: Bu durumda araba park alanını geçer ve kenardaki iki sensör de tekrar duvar veya araba görünceye dek ilerler. 
İki sensör de duvar gördüğü anda araç durur ve biraz geri gelerek sağa 45 derece döner. 
Geriye hareket ederken arka sensör, ölçüm yaparak park alanına girer ve sola doğru dönemeye başlar. 
Sola hareketi sırasında kenarlardaki sensörler sürekli ölçüm yapar ve iki sensörün ölçtüğü değer birbirine eşit oluncaya kadar sola dönmeye devam eder. Eşit olduğunda durur. 
Ön sensör ölçüm yapar ve 10 cm den küçük olana kadar ileri gider. 
10 cm den küçük ise durur ve park etme işlemi sona erer. 
Dik Park Durumu: Kenarlardaki sensörler aynı anda arabanın uzunluğundan fazla değer ölçmüş ise araba durur ve sola 90 derece dönüş yapar. 
Park alanına doğru hareket etmeye başlar. 
Bu esnada ön sensör sürekli ölçüm yapar ve ölçülen değer 10cm den küçük ise araba durur. 
Park işlemi tamamlanmış olur.
</br>
Mobil uygulamada ise aracın 4 yöne hareketini sağlayan butonlar, aracın park etmeye başlama komutunu veren park et butonu ve bluetooth sensörüyle araçla haberleşmesini sağlamaktadır.
</br>
Projenin algoritmasının ve projenin görselleri aşağıda mevcuttur.
</br>
</br>
**Aracın dış görünüşü**
</br>
</br>
![car](https://github.com/mehmetyalcinkaya/Otonom-Park/blob/master/Project%20Foto/car.png)
</br>
</br>
**Mobil uygulama**
</br>
</br>
![mobil](https://github.com/mehmetyalcinkaya/Otonom-Park/blob/master/Project%20Foto/mobilApplication.png)
</br>
</br>
**Paralel park Algoritması**
</br>
</br>
![paralelpark](https://github.com/mehmetyalcinkaya/Otonom-Park/blob/master/Project%20Foto/parallelParking1.png)
![paralelparkk](https://github.com/mehmetyalcinkaya/Otonom-Park/blob/master/Project%20Foto/parallelParking2.png)
